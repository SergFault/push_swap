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

int small_sort_b(t_list **stack_b)
{
	int val1;
	int val2;
	int val3;

	val1 = ((t_int_cont *)((*stack_b)->content))->index;
	val2 = ((t_int_cont *)((*stack_b)->next->content))->index;
	val3 = ((t_int_cont *)((*stack_b)->next->next->content))->index;
	if (val1 < val3 && val3 < val2)
	{
		ft_sx(stack_b, 'b', 1);
		ft_rx(stack_b, 'b', 1);
	} else if (val2 < val1 && val1 < val3)
	{
		ft_sx(stack_b, 'b', 1);
	}
	else if  (val3 < val1 && val1 < val2)
	{
		ft_rrx(stack_b, 'b', 1);
	}
	else if  (val3 < val2 && val2 < val1)
	{
		ft_sx(stack_b, 'b', 1);
		ft_rrx(stack_b, 'b', 1);
	}
	else if  (val2 < val3 && val3 < val1)
	{
		ft_rx(stack_b, 'b', 1);
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