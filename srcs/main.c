#include "ft_malcolm.h"

int main(int argc, char **argv)
{
	t_ctx ctx = {0};

	check_args(argc);

	parse_args(argv, &ctx);


	return (0);
}