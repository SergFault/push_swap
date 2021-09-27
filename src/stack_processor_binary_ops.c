#include "../includes/push_swap.h"

void	ft_ss(t_list **stack_a, t_list **stack_b, int write)
{
	ft_sx(stack_a, 'a', 0);
	ft_sx(stack_b, 'b', 0);
	if (write)
		ft_putstr_fd("ss\n", STDOUT_FILENO);
}

void	ft_rrr(t_list **stack_a, t_list **stack_b, int write)
{
	ft_rrx(stack_a, 'a', 0);
	ft_rrx(stack_b, 'b', 0);
	if (write)
		ft_putstr_fd("rrr\n", STDOUT_FILENO);
}
