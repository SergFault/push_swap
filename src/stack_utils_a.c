#include "../includes/push_swap.h"

int	has_lower(t_list *stack, int val)
{
	while (stack && cont(stack)->sorted == 0)
	{
		if (cont(stack)->index <= val)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	has_sorted (t_list *stack)
{
	while (stack->next)
	{
		if (cont(stack)->sorted)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	count_elements(t_list *stack)
{
	int	counter;

	counter = 0;
	while (stack)
	{
		counter++;
		stack = stack->next;
	}
	return (counter);
}

int	has_bigger(t_list *stack, int val)
{
	while (stack)
	{
		if (cont(stack)->index >= val)
			return (1);
		stack = stack->next;
	}
	return (0);
}

t_int_cont	*cont(t_list *lst)
{
	return ((t_int_cont *)lst->content);
}
