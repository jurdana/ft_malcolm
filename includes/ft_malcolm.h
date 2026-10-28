#ifndef FT_MALCOLM_H
# define FT_MALCOLM_H

# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <arpa/inet.h>

# define ETHERTYPE_ARP 		0x0806
# define ARP_HW_ETHERNET 	1
# define ARP_PROTO_IPV4 	0x0800
# define ARP_OP_REQUEST 	1
# define ARP_OP_REPLY 		2
# define MAC_LEN			6
# define IPV4_LEN			4

typedef struct s_eth
{									// octet
	uint8_t		ether_dest[6];		// 6
	uint8_t		ether_src[6];		// 6
	uint16_t	ether_type;			// 2

}	__attribute__((packed))	t_eth;

typedef struct s_arp
{									// octet
	uint16_t	hw_type;			// 2
	uint16_t	proto_type;			// 2
	uint8_t		hw_len;				// 1
	uint8_t		proto_len;			// 1
	uint16_t	opcode;				// 2
	uint8_t		sender_mac[6];		// 6
	uint8_t		sender_ip[4];		// 4
	uint8_t		target_mac[6];		// 6
	uint8_t		target_ip[4];		// 4

}	__attribute__((packed)) t_arp;

typedef struct s_ctx
{
	uint8_t	source_mac[6];
	uint8_t	target_mac[6];
	uint8_t	source_ip[4];
	uint8_t	target_ip[4];
	int		fd;
	int		if_index;

}	t_ctx;

// PARSE.C
void	check_args(int argc);
void	parse_args(char **argv, t_ctx *ctx);
void	parse_ip(char *ip_str, uint8_t *dest);
void	parse_mac(char *mac_str, uint8_t *dest);

// PRINT.C
void	print_mac_error(char *mac_str);



#endif