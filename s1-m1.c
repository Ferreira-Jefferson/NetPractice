/*
Módulo 1: Sistemas Numéricos e Conversão Base
1. Objetivo do Módulo: Dominar a representação interna e a conversão de valores
entre as bases Decimal e Binária, simulando um octeto (8 bits) ou um endereço IPv4
(32 bits).

Exercício Prático (Progressivo):
• Foco: Funções de conversão Decimal $ o$ Binário e Binário $ o$ Decimal para um
unsigned char (octeto).

• Tarefa: Crie um pequeno programa que defina uma função, digamos void
dec_para_bin(unsigned char octeto), que imprima o valor binário (exatamente 8
bits) desse octeto. Crie outra função, unsigned char bin_para_dec(const char*
bin_str), que faça o inverso.

Provocação de Raciocínio (Crucial):
• Quando você converte Decimal $ o$ Binário, você usa divisões ou operações
bitwise? Qual é mais eficiente para um computador e por quê?
• Onde você deve colocar os zeros à esquerda para garantir que a saída binária
tenha sempre 8 bits? O que acontece se você simplesmente usar %d ou %x do

printf para imprimir um valor inteiro em C?
3. Ponto de Consolidação: Se você consegue converter o valor 203 (decimal) para
11001011 (binário) e vice-versa, e entende que o computador armazena isso como
bits em um tipo inteiro, você dominou o básico.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *dec_para_bin(unsigned char octeto);
unsigned char bin_para_dec(const char *bin_str);

char *dec_para_bin(unsigned char octeto)
{
	int i = -1;
	char *bin_str = malloc(9);	
	while (i++ < 8)
		bin_str[7 - i] = ((octeto >> i) & 1) + '0';
	bin_str[8] = '\0';
	return (bin_str);
}

unsigned char bin_para_dec(const char *bin_str)
{
	unsigned char value = 0;

	while (*bin_str)
	{
		value <<= 1;
		value |= (*bin_str - '0') & 1;
		bin_str++;
	}
	return (value);

}

int main(int argc, char *argv[])
{
	if (argc == 1 || argc > 2)
	{
		printf("Informe um valor decimal entre [-128 e 255]\n");
		return (0);
	}
	int i = 0;
	while (argv[1][i])
	{
		if (!isdigit(argv[1][i]) && !isspace(argv[1][i]))
		{
			printf("Informe um valor decimalentre [-128 e 255]\n");
			return (0);
		}
		i++;
	}
	int value = atoi(argv[1]);
	if (value < -128 || value > 255)
	{
		printf("Informe um valor decimalentre [-128 e 255]\n");
		return (0);
	}

	printf("Original: %d\n", value);

	char *bin_str = dec_para_bin(value);
	printf("Decimal -> Binário: %s\n", bin_str);

	int decimal = bin_para_dec(bin_str);
	printf("Binário -> Decimal: %d\n", decimal);

	printf("Decimal com %%x: %x\n", decimal);

	return (0);
}