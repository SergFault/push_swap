#include "../includes/push_swap.h"

int	lo_e(t_list *stack, int val)
{
	if (stack)
	{
		if (cont(stack)->index <= val)
			return (1);
	}
	return (0);
}

int	bigger_e(t_list *stack, int val)
{
	if (stack)
	{
		if (cont(stack)->index >= val)
			return (1);
	}
	return (0);
}

int	is_next_eq(t_list *stack, int val)
{
	if (stack)
	{
		if (cont(stack)->index == val)
			return (1);
	}
	return (0);
}

int	is_chunk(t_list *stack, int chunk)
{
	if (!stack)
		return (0);
	if (cont(stack)->round == chunk)
		return (1);
	return (0);
}

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (cont(stack)->val >= cont(stack->next)->val)
			return (0);
		stack = stack->next;
	}
	return (1);
}
