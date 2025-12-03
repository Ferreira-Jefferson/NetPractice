/*
Módulo 5: O Salto Lógico: Roteamento e Interfaces
1. Objetivo do Módulo: Entender como a lógica do Subnetting (Módulos 1-4) é
aplicada para decidir se um pacote deve ser entregue diretamente na rede local ou
se deve ser enviado ao Roteador (Default Gateway).

Exercício Prático (Progressivo):
• Foco: Simulação da Tabela de Rotas e o papel do Gateway.

Tarefa: Crie uma função, int decidir_rota(unsigned int meu_ip, unsigned int
meu_mask, unsigned int destino_ip, unsigned int gateway_ip). Esta função deve
simular o processo de roteamento em um host:
1. Calcular o Endereço de Rede (Rede_A) do seu IP usando a sua máscara.
2. Calcular o Endereço de Rede (Rede_B) do IP de destino usando a sua máscara.
3. Comparar Rede_A com Rede_B.
4. Se forem iguais, retornar um código indicando "Entrega Direta". Se forem
diferentes, retornar um código indicando "Enviar para Gateway".

Provocação de Raciocínio (Crucial):
• Por que o Roteador precisa de duas ou mais interfaces, cada uma com seu próprio
IP e Máscara de Sub-rede? Qual é a implicação prática de um pacote destinado a
uma rede remota (Rede_A != Rede_B) ser roteado, em vez de entregue diretamente?
• Em um host, o que acontece se o Default Gateway for inacessível ou se pertencer
a uma sub-rede diferente da interface que está tentando usá-lo?
3. Ponto de Consolidação: Se você consegue explicar por que um pacote para
$192.168.1.10$ deve ir direto, mas um para $8.8.8.8$ deve ir para o Gateway
$192.168.1.1$ (dado o IP/Máscara $192.168.1.100/24$), você compreendeu o papel
do roteamento em nível de host.
*/

#include <math.h>
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

unsigned int get_network(int ip, int mask)
{
	return (ip & mask);
}

unsigned int get_mask(int cidr)
{
	if (!cidr)
		return (0);
	return (~0 << (32 - cidr));
}

int decidir_rota(unsigned int meu_ip, unsigned int meu_mask, 
	unsigned int destino_ip, unsigned int gateway_ip)
{
	unsigned int net_a = get_network(meu_ip, meu_mask);
	unsigned int net_b = get_network(destino_ip, meu_mask);

	if (net_a == net_b)
	{
		printf("Entrega Direta para: %s\n", format_ip(net_a));
		return (0);
	}
	printf("Enviar para Gateway: %s\n", format_ip(gateway_ip));
	return (1);
}

int main(){
	int cidr = 24;
	unsigned int meu_ip = (192 << 24) | (168 << 16) | (1 << 8) | 100;
	unsigned int meu_mask = get_mask(cidr);
	unsigned int gateway_ip = (192 << 24) | (168 << 16) | (1 << 8) | 1;
	
	unsigned int destino_ip =  (192 << 24) | (168 << 16) | (1 << 8) | 10;
	decidir_rota(meu_ip, meu_mask, destino_ip, gateway_ip);
	
	destino_ip =  (8 << 24) | (8 << 16) | (8 << 8) | 8;
	decidir_rota(meu_ip, meu_mask, destino_ip, gateway_ip);
}