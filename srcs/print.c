#include "ft_malcolm.h"

void	print_mac_error(char *mac_str)
{
	fprintf(stderr, "ft_malcolm: invalid MAC address: %s\n", mac_str);
	exit(1);
}