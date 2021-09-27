#include "../includes/push_swap.h"

void	error_handler(void)
{
	ft_putstr_fd("Error\n", STDOUT_FILENO);
	exit(EXIT_FAILURE);
}

void	clear_arr(char **str_ar)
{
	while (*str_ar)
	{
		free(*str_ar);
		(void) *str_ar++;
	}
}
