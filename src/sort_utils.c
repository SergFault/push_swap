#include "../includes/push_swap.h"

void ft_sort(t_list *list)
{
	int was_sorting;
	t_list *start;
	void *temp;

	start = list;
	was_sorting = 1;
	while(was_sorting) {
		was_sorting = 0;
		while (list && list->next) {
			if (((t_int_cont *) (list->content))->val >
				((t_int_cont *) (list->next->content))->val) {
				temp = list->content;
				list->content = list->next->content;
				list->next->content = temp;
				was_sorting = 1;
			}
			list = list->next;
		}
		list = start;
	}
}

void index_stack(t_list *stack, t_list *sorted)
{
	int index;
	t_list *iter;

	iter = stack;
	index = 0;
	while(sorted)
	{
		while (iter)
		{
			if (((t_int_cont*)iter->content)->val ==
				(((t_int_cont*)(sorted->content))->val))
			{
				((t_int_cont*)iter->content)->index = index++;
				break;
			}
			iter = iter->next;
		}
		iter = stack;
		sorted = sorted->next;
	}
}

int find_pos(t_list *stack, int index)
{
	int	c;

	c = 0;
	while (stack)
	{
		if (CONT(stack)->index == index)
			return (c);
		stack = stack->next;
		c++;
	}
	return (c);
}

int find_min_index(t_list *stack)
{
	int	min_index;

	min_index = 0;
	if (stack)
		min_index = CONT(stack)->index;
	while (stack)
	{
		if (CONT(stack)->index < min_index)
			min_index = CONT(stack)->index;
		stack = stack->next;
	}
	return (min_index);
}

int four_sort(t_set *set)
{
	int action;

	if (find_pos(set->stack_a, 0) <= 1)
		action = RA;
	else
		action = RRA;

	while (CONT(set->stack_a)->index != 0)
		perform(action, set);
	perform(PB, set);
	small_sort(set);
	perform(PA, set);
	return (0);
}

int five_sort(t_set *set)
{
	int action;

	if (find_pos(set->stack_a, 0) <= 2)
		action = RA;
	else
		action = RRA;
	while (CONT(set->stack_a)->index != 0)
		perform(action, set);
	perform(PB, set);
	if (find_pos(set->stack_a, 1) <= 2)
		action = RA;
	else
		action = RRA;
	while (CONT(set->stack_a)->index != 1)
		perform(action, set);
	perform(PB, set);

	small_sort(set);
	perform(PA, set);
	perform(PA, set);
	return (0);
}

int small_sort(t_set *set)
{
	int min_index;

	min_index = find_min_index(set->stack_a);
	if (CONT(set->stack_a)->index == min_index + 2)
		perform(RA, set);
	if (CONT(set->stack_a->next)->index == min_index + 2)
		perform(RRA, set);
	if (CONT(set->stack_a->next)->index == min_index)
		perform(SA, set);
	return (0);
}

void rra_or_rrr(t_set *set)
{

	if (set->stack_b && set->stack_a && !is_next_eq(set->stack_b,
													set->s_data->next))

//	if (set->stack_b && set->stack_a && last_bigger(set->stack_b))
	{
//		PRINT
		perform(RRR, set);
//		PRINT
	}
	else
		perform(RRA, set);
}

int try_swap_a(t_set *set)
{
	if (set->stack_a && set->stack_a->next && !needs_rotate_a(set)
		&& CONT(set->stack_a->next)->index == set->s_data->next)
	{
		perform(SA, set);
		return (1);
	}
	return (0);
}

int try_push_last_b(t_set *set)
{
	t_list *iter;
	iter = set->stack_b;
	int c;

	c = 0;
	while (iter && iter->next)
	{
		iter = iter->next;
		c++;
	}

	if (is_next_eq(iter, set->s_data->next) && c > 2)
	{
//		PRINT
		perform(RRB, set);
		CONT(set->stack_b)->sorted = 1;
		set->s_data->next++;
		perform(PA, set);
		perform(RA, set);
		return (1);
	}
	return (0);
}


int get_stack_data_round(t_set *set, t_list *stack)
{
	int min;
	int max;
	int round;

	round = (((t_int_cont *)stack->content)->round);
	set->s_data->size = 0;
	min = ((t_int_cont *)stack->content)->index;
	max = ((t_int_cont *)stack->content)->index;
	while(stack)
	{
		if ((((t_int_cont *)stack->content)->round == round) &&
			!(((t_int_cont *)stack->content)->sorted))
		{
			if (((t_int_cont *) stack->content)->index > max)
				max = ((t_int_cont *) stack->content)->index;
			if (((t_int_cont *) stack->content)->index < min)
				min = ((t_int_cont *) stack->content)->index;
			set->s_data->size++;
		}
		stack = stack->next;
	}
//	set->s_data->round_c = round_c;
	set->s_data->max = max;
	set->s_data->min = min;
	set->s_data->mid = min + ((max - min) / 2);
	return (1);
}

int split_to_a(t_set *set)
{
	get_stack_data_round(set, set->stack_b);
	while(has_bigger(set->stack_b, set->s_data->mid))
	{
		if (try_push_last_b(set))
			continue ;
		if (is_next_eq(set->stack_b, set->s_data->next))
		{
			to_sorted('b', set);
			continue ;
		}
		else if (bigger_e(set->stack_b, set->s_data->mid))
		{
			CONT(set->stack_b)->round = set->s_data->round_c;
			perform(PA, set);
		}else
		{
			perform(RB, set);
		}
	}
	set->s_data->round_c++;
	return (1);
}

int split_to_b(t_set *set){
	int chunk;

	get_stack_data_round(set, set->stack_a);
	chunk =  CONT(set->stack_a)->round;
	while(((has_lower(set->stack_a, set->s_data->mid)
			|| CONT(set->stack_a)->round > 0))
		  && is_chunk(set->stack_a, chunk) && !CONT(set->stack_a)->sorted)
	{
		if (try_swap_a(set))
			continue ;
		if (is_next_eq(set->stack_a, set->s_data->next) && !needs_rotate_a(set))
		{
			to_sorted('a', set);
			continue ;
		}
		else if (lo_e(set->stack_a, set->s_data->mid)
				 || CONT(set->stack_a)->round > 0)
		{
			perform(PB, set);
		}
		else
		{
//			ra_or_rr(set);
			perform(RA, set);
		}
	}
	while (needs_rotate_a(set))
	{
//		perform(RRA, set);
		rra_or_rrr(set);
	}
//	print_stacks(set->stack_a, set->stack_b);
	return (1);
}

int is_last_sorted(t_list *stack)
{
	if (!stack)
		return (0);
	while(stack->next)
	{
		stack = stack->next;
	}
	if (CONT(stack)->sorted)
		return (1);
	return (0);
}


int first_split(t_set *set){


	get_stack_data_round(set, set->stack_a);
	while(has_lower(set->stack_a, set->s_data->mid))
	{
		if (is_next_eq(set->stack_a, set->s_data->next))
		{
			set->s_data->next++;
			CONT(set->stack_a)->sorted = 1;
			perform(PB, set);
			perform(RB, set);
			continue ;
		}
		if (lo_e(set->stack_a, set->s_data->mid)
			|| CONT(set->stack_a)->round > 0)
		{
			perform(PB, set);
		}
		else
		{
//			ra_or_rr(set);
			perform(RA, set);
		}
	}
	while(is_last_sorted(set->stack_b))
	{
		perform(RRB, set);
		perform(PA, set);
	}
	while(CONT(set->stack_a)->sorted)
	{
		perform(RA, set);
	}
	return (1);
}

int default_sort(t_set *set)
{
	first_split(set);
	while (!((t_int_cont *) set->stack_a->content)->sorted)
	{
		while (set->stack_b)
		{
			split_to_a(set);
		}
		split_to_b(set);
	}
	return (0);
}


int small_sort_a(t_list **stack_a)
{
	int val1;
	int val2;
	int val3;

	val1 = ((t_int_cont *)((*stack_a)->content))->index;
	val2 = ((t_int_cont *)((*stack_a)->next->content))->index;
	val3 = ((t_int_cont *)((*stack_a)->next->next->content))->index;
	if (val1 < val3 && val3 < val2)
	{
		ft_sx(stack_a, 'a', 1);
		ft_rx(stack_a, 'a', 1);
	} else if (val2 < val1 && val1 < val3)
	{
		ft_sx(stack_a, 'a', 1);
	}
	else if  (val3 < val1 && val1 < val2)
	{
		ft_rrx(stack_a, 'a', 1);
	}
	else if  (val3 < val2 && val2 < val1)
	{
		ft_sx(stack_a, 'a', 1);
		ft_rrx(stack_a, 'a', 1);
	}
	else if  (val2 < val3 && val3 < val1)
	{
		ft_rx(stack_a, 'a', 1);
	}
	return (1);
}

int small_sort_desc(t_list **stack_b)
{
	int val1;
	int val2;
	int val3;

	val1 = ((t_int_cont *)((*stack_b)->content))->index;
	val2 = ((t_int_cont *)((*stack_b)->next->content))->index;
	val3 = ((t_int_cont *)((*stack_b)->next->next->content))->index;
	if (val1 > val3 && val3 > val2)
	{
		ft_sx(stack_b, 'b', 1);
		ft_rx(stack_b, 'b', 1);
	} else if (val2 > val1 && val1 > val3)
	{
		ft_sx(stack_b, 'b', 1);
	}
	else if  (val3 > val1 && val1 > val2)
	{
		ft_rrx(stack_b, 'b', 1);
	}
	else if  (val3 > val2 && val2 > val1)
	{
		ft_sx(stack_b, 'b', 1);
		ft_rrx(stack_b, 'b', 1);
	}
	else if  (val2 > val3 && val3 > val1)
	{
		ft_rx(stack_b, 'b', 1);
	}
	return (1);
}