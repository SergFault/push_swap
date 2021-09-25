#include "../includes/push_swap.h"

#include <stdio.h>


void print_stacks(t_list *stack_a, t_list *stack_b)
{
	printf("stack A\t\t\t\t\t\t\t\tstack B\n");
	while(stack_a || stack_b)
	{
		if (stack_a) {
			printf("index %d \t", ((t_int_cont *) stack_a->content)->index);
			printf("round_c %d \t", ((t_int_cont *) stack_a->content)->round);
			printf("val %d \t", ((t_int_cont *) stack_a->content)->val);
			printf("sorted %d \t|", ((t_int_cont *) stack_a->content)->sorted);
			stack_a = stack_a->next;
		} else
		{
			printf("NULL      \tNULL      \tNULL       \tNULL  \t|");
		}
		printf("\t\t");
		if (stack_b) {
			printf("index %d \t", ((t_int_cont *) stack_b->content)->index);
			printf("round_c %d \t", ((t_int_cont *) stack_b->content)->round);
			printf("val %d \t", ((t_int_cont *) stack_b->content)->val);
			printf("sorted %d \t|", ((t_int_cont *) stack_b->content)->sorted);
			stack_b = stack_b->next;
		} else
		{
			printf("NULL      \tNULL      \tNULL       \tNULL  \t|");
		}
		printf("\n");
	}
}

int get_args(int argc, char **argv, t_list **lst)
{
    int c;
	t_int_cont *temp;

    c = 1;
    if (argc < 2)
        return (-1);
    while (c < argc)
    {
		temp = new_int(argv[c]);
        ft_lstadd_back(lst, ft_lstnew(temp));
		c++;
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

int last_lower(t_list *stack)
{
	t_list *iter;

	iter = stack;
	while(iter->next)
	{
		iter = iter->next;
	}
	if ( CONT(iter)->index < CONT(stack)->index)
		return (1);
	return (0);
}

int last_bigger(t_list *stack)
{
	t_list *iter;

	iter = stack;
	while(iter->next)
	{
		iter = iter->next;
	}
	if ( CONT(iter)->index > CONT(stack)->index)
		return (1);
	return (0);
}

void ra_or_rr(t_set *set)
{

//	if (set->stack_b && set->stack_a
//				&& !is_next_eq(set->stack_b, set->s_data->next)
//				&& last_lower(set->stack_b))

		if (set->stack_b && set->stack_a && last_bigger(set->stack_b))
	{
//		PRINT
			perform(RR, set);
//		PRINT
	}
	else
		perform(RA, set);
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

int split_to_b(t_set *set){
	int chunk;

	get_stack_data_round(set, set->stack_a);
	chunk =  CONT(set->stack_a)->round;
	while(((has_lower(set->stack_a, set->s_data->mid)
	|| CONT(set->stack_a)->round > 0))
			&& is_cur(set->stack_a, chunk) && !CONT(set->stack_a)->sorted)
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
int try_push_sorted(t_set *set)
{
	if (!set->stack_b)
		return (0);
	if (CONT(set->stack_b)->index == set->s_data->next)
	{
//		PRINT
		to_sorted('b', set);
		return (1);
	}
	return (0);
}

int split_to_a(t_set *set)
{
	get_stack_data_round(set, set->stack_b);
	while(has_bigger(set->stack_b, set->s_data->mid))
	{
//		if (get_stack_size(set->stack_b) == 3)
//			small_sort_b(&set->stack_b);
//		if (try_push_sorted(set))
//			continue ;
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
//	print_stacks(set->stack_a, set->stack_b);
	return (1);
}

int sort(t_set *set)
{
	first_split(set);
	while(!((t_int_cont *)set->stack_a->content)->sorted)
	{
		while (set->stack_b) {

//			ft_putstr_fd("split to a\n", 1);
//			print_stacks(set->stack_a, set->stack_b);

			split_to_a(set);
		}
//		print_stacks(set->stack_a, set->stack_b);
//		ft_putstr_fd("split to b\n", 1);

		split_to_b(set);
//		print_stacks(set->stack_a, set->stack_b);
	}
//	PRINT
	return 0;
}

int main(int argc, char** argv)
{
	t_set set;

	init_set(&set);

	get_args(argc, argv, &set.int_lst);
	set.sorted = copy_stack(set.int_lst);
	ft_sort(set.sorted);
	set.stack_a = copy_stack(set.int_lst);
	index_stack(set.stack_a, set.sorted);
	sort(&set);
}
