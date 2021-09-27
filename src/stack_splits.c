#include "../includes/push_swap.h"

void	first_split(t_set *set)
{
	get_stack_data_round(set, set->stack_a);
	while (has_lower(set->stack_a, set->s_data->mid))
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
			perform(PB, set);
		else
			perform(RA, set);
	}
	while (is_last_sorted(set->stack_b))
	{
		perform(RRB, set);
		perform(PA, set);
	}
	while (CONT(set->stack_a)->sorted)
		perform(RA, set);
}

int	split_to_b(t_set *set)
{
	int	chunk;

	get_stack_data_round(set, set->stack_a);
	chunk = CONT(set->stack_a)->round;
	while (((has_lower(set->stack_a, set->s_data->mid)
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
			perform(PB, set);
		else
			perform(RA, set);
	}
	while (needs_rotate_a(set))
		rra_or_rrr(set);
	return (1);
}

int	split_to_a(t_set *set)
{
	get_stack_data_round(set, set->stack_b);
	while (has_bigger(set->stack_b, set->s_data->mid))
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
		}
		else
			perform(RB, set);
	}
	set->s_data->round_c++;
	return (1);
}
