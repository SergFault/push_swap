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
			if ( ((t_int_cont*)iter->content)->val ==
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