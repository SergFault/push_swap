#include "../includes/push_swap.h"

int get_args(int argc, char **argv, t_list **lst)
{
	int c;
	char **splitted;

	splitted = NULL;
	(void) splitted;
	c = 1;
	if (argc < 2)
		exit(EXIT_FAILURE);
	while (c < argc)
	{
		if (check_arg(c, argv))
			splitted = split_arg(argv[c]);
		else
			error_handler();
		push_to_list(splitted, lst);
		c++;
	}
	return (0);
}