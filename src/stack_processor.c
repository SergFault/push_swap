#include "../includes/push_swap.h"

void ft_sx(t_list **stack_x, char stack_identity, int write)
{
	void *temp;
	t_list *stack;

	if (!stack_x || !*stack_x || !(*stack_x)->next)
		return ;
	stack = *stack_x;
	temp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp;
	if (write)
	{
		ft_putchar_fd('s',1);
		ft_putchar_fd(stack_identity, 1);
		ft_putchar_fd('\n', 1);
	}
}

void ft_ss(t_list **stack_a, t_list **stack_b, int write)
{
	ft_sx(stack_a, 'a', 0);
	ft_sx(stack_b, 'b', 0);
	if (write)
		ft_putstr_fd("ss\n", STDOUT_FILENO);
}