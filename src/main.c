#include "../includes/push_swap.h"

#include <stdio.h>


t_int_cont *new_int(char *str_int)
{
	int i;
	t_int_cont *cont;

	i = ft_atoi(str_int);
	cont = (t_int_cont *) malloc(sizeof(t_int_cont));
	cont->val = i;
	cont->index = 0;
	cont->round = 0;
	cont->sorted = 0;
	return cont;
}

void print_stacks(t_list *stack_a, t_list *stack_b)
{
	printf("stack A\t\t\t\t\t\t\t\tstack B\n");
	while(stack_a || stack_b)
	{
		if (stack_a) {
			printf("index %d \t", ((t_int_cont *) stack_a->content)->index);
			printf("round %d \t", ((t_int_cont *) stack_a->content)->round);
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
			printf("round %d \t", ((t_int_cont *) stack_b->content)->round);
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


void init_set(t_set *set)
{
	set->s_data->next = 0;
	set->s_data->max = 0;
	set->s_data->mid = 0;
	set->s_data->min = 0;
	set->s_data->size = 0;
	set->s_data->round = 1;
	set->int_lst = NULL;
	set->sorted = NULL;
	set->stack_a = NULL;
	set->stack_b = NULL;
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
	set->s_data->round = round;
	set->s_data->max = max;
	set->s_data->min = min;
	set->s_data->mid = min + ((max - min) / 2);
	return (1);
}

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

int is_next(t_list *stack, int val)
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

int split_to_b(t_set *set){
	int chunk;

	get_stack_data_round(set, set->stack_a);
	chunk = set->s_data->round;
	while(has_lower(set->stack_a, set->s_data->mid) && is_cur(set->stack_a, chunk))
	{
		if (is_next(set->stack_a, set->s_data->next) && !needs_rotate_a(set))
		{
			to_sorted('a', set);
			continue ;
		}
		else if (lo_e(set->stack_a, set->s_data->mid))
		{
			perform(PB, set);
		}else
		{
			perform(RA, set);
		}
	}
	while (needs_rotate_a(set))
	{
		perform(RRA, set);
	}
//	print_stacks(set->stack_a, set->stack_b);
	return (1);
}


int split_to_a(t_set *set)
{
	get_stack_data_round(set, set->stack_b);
	set->s_data->round++;
	while(has_bigger(set->stack_b, set->s_data->mid))
	{
		if (is_next(set->stack_b, set->s_data->next))
		{
			to_sorted('b', set);
			continue ;
		}
		else if (bigger_e(set->stack_b, set->s_data->mid))
		{
			CONT(set->stack_b)->round = set->s_data->round;
			perform(PA, set);
		}else
		{
			perform(RB, set);
		}
	}
//	print_stacks(set->stack_a, set->stack_b);
	return (1);
}

int sort(t_set *set)
{
	while(!((t_int_cont *)set->stack_a->content)->sorted)
	{

//		print_stacks(set->stack_a, set->stack_b);
//		ft_putstr_fd("split to b\n", 1);

		split_to_b(set);
		while (set->stack_b) {

//			ft_putstr_fd("split to a\n", 1);
//			print_stacks(set->stack_a, set->stack_b);

			split_to_a(set);
		}
//		print_stacks(set->stack_a, set->stack_b);
	}
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
