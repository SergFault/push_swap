#include "../includes/push_swap.h"

int has_lower(t_list *stack, int val)
{
	while(stack && CONT(stack)->sorted == 0)
	{
		if (CONT(stack)->index <= val)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int has_bigger(t_list *stack, int val)
{
	while(stack)
	{
		if (CONT(stack)->index >= val)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int lo_e(t_list *stack, int val)
{
	if (stack)
	{
		if (CONT(stack)->index <= val)
			return (1);
	}
	return (0);
}

int bigger_e(t_list *stack, int val)
{
	if (stack)
	{
		if (CONT(stack)->index >= val)
			return (1);
	}
	return (0);
}

int is_next_eq(t_list *stack, int val)
{
	if (stack)
	{
		if (CONT(stack)->index == val)
			return (1);
	}
	return (0);
}

void to_sorted(char location, t_set *set)
{
	if (location == 'a')
	{
		CONT(set->stack_a)->sorted = 1;
		perform(RA, set);
		set->s_data->next++;
	}
	else
	{
		CONT(set->stack_b)->sorted = 1;
		perform(PA, set);
		perform(RA, set);
		set->s_data->next++;
	}
}

int is_cur(t_list *stack, int chunk)
{
	if (!stack)
		return 0;
	if (CONT(stack)->round == chunk)
		return (1);
	return (0);
}

int has_sorted (t_list *stack)
{
	while(stack->next) {
		if (CONT(stack)->sorted)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int needs_rotate_a(t_set *set)
{
	t_list *last;
	last = set->stack_a;
	while(last->next)
		last = last->next;
	if (CONT(last)->sorted == 0 && has_sorted(set->stack_a))
		return (1);
	return (0);
}


int get_stack_size(t_list *stack)
{
	int c;

	c = 0;
	while(stack)
	{
		stack = stack->next;
		c++;
	}
	return (c);
}