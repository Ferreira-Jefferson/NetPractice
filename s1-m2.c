/*
Módulo 2: Manipulação de Bits e a Lógica da Máscara
1. Objetivo do Módulo: Implementar a lógica da Máscara de Sub-rede através da
operação AND bitwise (&) para isolar a porção de Rede de um endereço IP.

Exercício Prático (Progressivo):
• Foco: O Operador AND bitwise (&) e o conceito de Máscara.

Tarefa: Crie um programa que faça o seguinte:
1. Defina dois unsigned int: endereco_ip (ex: $192.168.10.15$) e mascara_subrede
(ex: $255.255.255.0$). (Dica: Pense em como representar esses 4 octetos em um
único unsigned int).
2. Crie uma função, unsigned int calcular_endereco_rede(unsigned int ip,
unsigned int mask), que use a operação AND para retornar o endereço da Rede.
3. Imprima o IP, a Máscara e o Endereço de Rede resultante no formato Decimal
Pontuado (ex: $192.168.10.0$).

Provocação de Raciocínio (Crucial):
• Como você consegue empacotar os quatro octetos (4 bytes) do IP em um único

unsigned int (4 bytes)? Quais operadores bitwise (<<, |) são essenciais para isso?
• Se a Máscara é $255.255.255.0$, o que acontece com a porção Host quando o
AND é aplicado? Por que essa porção é zerada e o que isso significa
conceitualmente em termos de rede?
3. Ponto de Consolidação: Se você consegue isolar corretamente a porção Rede
(onde os bits da máscara são 1) da porção Host (onde os bits da máscara são 0),
você está pronto para o Subnetting.
*/

#include <stdio.h>

unsigned int calcular_endereco_rede(unsigned int ip, unsigned int mask)
{
	return ip & mask;
}

int main(void)
{
	unsigned int ip = (192 << 24) | (168 << 16) | (10 << 8) | 15;
	unsigned int mask = (255 << 24) | (255 << 16) | (255 << 8) | 0;

	unsigned int network = calcular_endereco_rede(ip, mask);
	printf("net[%d.%d.%d] - host[%d]\n", (network >> 24) & 0xFF, (network >> 16) & 0xFF, (network >> 8) & 0xFF, (network) & 0xFF);
}