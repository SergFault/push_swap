#include "../includes/push_swap.h"

int	small_sort(t_set *set)
{
	int	min_index;

	min_index = find_min_index(set->stack_a);
	if (CONT(set->stack_a)->index == min_index + 2)
		perform(RA, set);
	if (CONT(set->stack_a->next)->index == min_index + 2)
		perform(RRA, set);
	if (CONT(set->stack_a->next)->index == min_index)
		perform(SA, set);
	return (0);
}

int	four_sort(t_set *set)
{
	int	action;

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

int	five_sort(t_set *set)
{
	int	action;

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

int	default_sort(t_set *set)
{
	first_split(set);
	while (!((t_int_cont *) set->stack_a->content)->sorted)
	{
		while (set->stack_b)
			split_to_a(set);
		split_to_b(set);
	}
	return (0);
}

void	ft_sort(t_list *list)
{
	int		was_sorting;
	t_list	*start;
	void	*temp;

	start = list;
	was_sorting = 1;
	while (was_sorting)
	{
		was_sorting = 0;
		while (list && list->next)
		{
			if (((t_int_cont *)(list->content))->val >
				((t_int_cont *)(list->next->content))->val)
			{
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
