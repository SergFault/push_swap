#include "../includes/push_swap.h"

int	sort(t_set *set)
{
	int	elements_c;

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
	return (0);
}

int	main(int argc, char **argv)
{
	t_set	set;

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
