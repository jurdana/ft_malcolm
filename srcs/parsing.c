#include "ft_malcolm.h"

void	check_args(int argc)
{
	if (getuid() != 0)
	{
		fprintf(stderr, "Root privilege needed.\n");
		printf("\n\n\n\n\n\n\n Helpers print for later \n\n\n\n\n\n");
		exit(1);
	}
	if (argc == 1)
	{
		printf("\n\n\n\n\n\n\n Helpers print for later \n\n\n\n\n\n");
		exit(1);
	}
	if (argc != 5)
	{
		fprintf(stderr, "A total of 4 arguments is needed.\n");
		exit(1);
	}
}

void	parse_ip(char *ip_str, uint8_t *dest)
{
	if (inet_pton(AF_INET, ip_str, dest) != 1)
	{
		fprintf(stderr, "ft_malcolm: invalid IP address: %s\n", ip_str);
		exit(1);
	}
}

int	hex_char_to_val(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (-1);
}

void	parse_mac(char *mac_str, uint8_t *dest)
{
	int i = 0;
	int j = 0;
	int v1 = 0;
	int v2 = 0;
	while (j < 6)
	{
		v1 = hex_char_to_val(mac_str[i]);
		if (v1 == -1)
			print_mac_error(mac_str);
		v2 = hex_char_to_val(mac_str[i + 1]);
		if (v2 == -1)
			print_mac_error(mac_str);
		dest[j] = v1 * 16 + v2;
		i += 2;
		if (j < 5)
		{
			if (mac_str[i] != ':')
				print_mac_error(mac_str);
			i++;
		}
		j++;
	}
	if (mac_str[i] != '\0')
		print_mac_error(mac_str);
}

void	parse_args(char **argv, t_ctx *ctx)
{
	parse_ip(argv[1], ctx->source_ip);
	parse_mac(argv[2], ctx->source_mac);
	parse_ip(argv[3], ctx->target_ip);
	parse_mac(argv[4], ctx->target_mac);

}