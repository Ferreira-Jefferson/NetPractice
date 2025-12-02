/*
Módulo 4: Subnetting - Cálculo de Hosts Válidos e Casos
Especiais
1. Objetivo do Módulo: Entender como a mudança no prefixo CIDR afeta o número
de Hosts Válidos e focar em sub-redes pequenas (como $/30$).

Exercício Prático (Progressivo):
• Foco: Cálculo $2^n$ e manipulação de faixas.

Tarefa:
1. Crie uma função int calcular_hosts_validos(int prefixo_cidr) que retorne o
número de hosts utilizáveis (total de endereços menos 2 - Rede e Broadcast).
2. Simule o cálculo de uma sub-rede $/30$. Receba um endereço IP de rede (ex:
$10.0.0.0$) e um prefixo $/30$. Imprima: o Endereço da Rede, o Primeiro Host
Válido, o Último Host Válido e o Endereço de Broadcast.
Provocação de Raciocínio (Crucial):
• Na função calcular_hosts_validos, por que é crucial subtrair 2? O que você faz se
o prefixo for $/32$ ou $/31$? O que a RFC 3021 permite para $/31$ e qual é a
implicação prática disso (dica: links ponto-a-ponto).
• Se você tem o endereço de Rede e o Broadcast, como você obtém o Primeiro
Host Válido e o Último Host Válido usando apenas a aritmética de ponteiros e o
incremento (++) e decremento (--) no unsigned int que armazena o endereço?
3. Ponto de Consolidação: Se você entende que o prefixo $/30$ é o mínimo para
ter dois hosts utilizáveis em links ponto-a-ponto tradicionais e consegue calcular essa
faixa perfeitamente, o domínio sobre o Subnetting está consolidado.
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

char *define_ip(int octetos)
{
	struct in_addr addr;
	addr.s_addr = htonl(octetos);

	char *str = malloc(INET_ADDRSTRLEN);
	inet_ntop(AF_INET, &addr, str, INET_ADDRSTRLEN);
	return (str);
}

int calcular_hosts_validos(int prefixo_cidr)
{
	return ((int) pow(2, 32 - prefixo_cidr) - 2);
}

unsigned int get_mask(int cidr)
{
	if (!cidr)
		return (0);
	return (~0 << (32 - cidr));
}

unsigned int get_wildcard(int mask)
{
	return (~mask);
}

unsigned int get_network(int ip, int mask)
{
	return (ip & mask);
}

unsigned int get_first_host(int network)
{
	return (network + 1);
}

unsigned int get_broadcast(int network, int wildcard)
{
	return (network | wildcard);
}

unsigned int get_last_host(int broadcast)
{
	return (broadcast - 1);
}
int main()
{
	unsigned int ip = (10 << 24) | 0;
	unsigned int cidr = 30;
	unsigned int mask = get_mask(cidr);
	unsigned int network = get_network(ip, mask);
	unsigned int wildcard = get_wildcard(mask);
	unsigned int broadcast = get_broadcast(network, wildcard);
	unsigned int first_host = get_first_host(network);
	unsigned int last_host = get_last_host(broadcast);

	printf("hosts válidos: %d\n", calcular_hosts_validos(cidr));
	printf("ip: %s\n", define_ip(ip));
	printf("mask: %s\n", define_ip(mask));
	printf("wildcard: %s\n", define_ip(wildcard));
	printf("network: %s\n", define_ip(network));
	printf("broadcast: %s\n", define_ip(broadcast));
	printf("1º host: %s\n", define_ip(first_host));
	printf("last host: %s\n", define_ip(last_host));

	return (0);
}