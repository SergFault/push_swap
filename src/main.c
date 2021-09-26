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

int sort(t_set *set)
{
	int elements_c;

	elements_c = count_elements(set->stack_a);
	if (elements_c == 2)
		perform(RA, set);
	else if (elements_c == 3)
		small_sort(set);
	else if (elements_c == 4)
		four_sort(set);
	else if (elements_c == 5)
		five_sort(set);
	else
		default_sort(set);
	return 0;
}



int main(int argc, char** argv)
{
	t_set set;

	init_set(&set);
	get_args(argc, argv, &set.int_lst);

	if (!is_sorted(set.int_lst))
	{
		if (!check_repeat(set.int_lst))
		{
			set.sorted = copy_stack(set.int_lst);
			ft_sort(set.sorted);
			set.stack_a = copy_stack(set.int_lst);
			index_stack(set.stack_a, set.sorted);
			sort(&set);
		}
		else
		{
			error_handler();
		}
	}
}
