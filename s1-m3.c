/*
Módulo 3: Notação CIDR e Cálculo do Endereço de Broadcast
1. Objetivo do Módulo: Entender a Notação CIDR (/n) e usá-la para calcular a
Máscara de Sub-rede e, em seguida, o Endereço de Broadcast.

Exercício Prático (Progressivo):
• Foco: Geração de Máscara a partir do prefixo /n e o Operador OR bitwise (|).

Tarefa:
1. Crie uma função unsigned int prefixo_para_mascara(int prefixo_cidr) que
receba um valor n (ex: 24) e retorne o unsigned int representando a máscara (ex:
$255.255.255.0$). (Dica: ~0 é um bom ponto de partida).
2. Crie uma função para calcular o Endereço de Broadcast. Lembre-se que o
Broadcast é o endereço da Rede com todos os bits da porção Host ligados (setados
para 1).
3. Calcule o Wildcard Mask (o inverso da Máscara de Sub-rede) e utilize-o para
calcular o Broadcast.

Provocação de Raciocínio (Crucial):
• O que a operação NOT bitwise (~) faz com a máscara gerada a partir do prefixo
CIDR? Como você pode usar isso para criar um "coringa" (Wildcard Mask) que te dá
apenas os bits da porção Host?
• Por que a operação OR bitwise (|) do Endereço de Rede com o Wildcard Mask
resulta no Endereço de Broadcast? Qual a lógica por trás de usar o OR com os bits
da porção Host?
3. Ponto de Consolidação: Se para o IP $10.1.1.100$ com prefixo $/16$ você
consegue calcular o Endereço de Rede ($10.1.0.0$) e o Endereço de Broadcast
($10.1.255.255$), você domina o conceito central.
*/

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h> 

char *format_ip(unsigned int octetos)
{
	struct in_addr addr;
    addr.s_addr = htonl(octetos);
    char *str = malloc(INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &addr, str, INET_ADDRSTRLEN);
	return (str);
}
unsigned int prefixo_para_mascara(int prefixo_cidr)
{
	if (!prefixo_cidr)
		return (0);
	return (~0 << (32 - prefixo_cidr));
}

unsigned int obter_broadcast(unsigned int ip, unsigned int mask)
{
	unsigned int network = ip & mask;
	unsigned int broadcast = network | ~mask;
	return (broadcast);
}

unsigned int obter_wildcard_mask(unsigned int mask)
{
	return (~mask);
}

int main()
{
	unsigned int ip = (192 << 24) | (168 << 16) | (1 << 8) | 10;
	unsigned int cidr = 24;
	printf("ip: %s\n", format_ip(ip));

	unsigned int mask = prefixo_para_mascara(cidr);
	printf("Mask: %s\n", format_ip(mask));

	unsigned int broadcast = obter_broadcast(ip, mask);
	printf("broadcast: %s\n", format_ip(broadcast));

	unsigned int wildcard = obter_wildcard_mask(mask);
	printf("wildcard: %s\n", format_ip(wildcard));
}