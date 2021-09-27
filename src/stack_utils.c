#include "../includes/push_swap.h"

void	to_sorted(char location, t_set *set)
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

int	needs_rotate_a(t_set *set)
{
	t_list	*last;

	last = set->stack_a;
	while (last->next)
		last = last->next;
	if (CONT(last)->sorted == 0 && has_sorted(set->stack_a))
		return (1);
	return (0);
}

int	get_stack_size(t_list *stack)
{
	int	c;

	c = 0;
	while (stack)
	{
		stack = stack->next;
		c++;
	}
	return (c);
}

t_list	*copy_stack(t_list *list)
{
	t_list		*new;
	t_int_cont	*new_content;

	new = NULL;
	while (list)
	{
		new_content = malloc(sizeof (t_int_cont));
		new_content->index = ((t_int_cont *)(list->content))->index;
		new_content->val = ((t_int_cont *)(list->content))->val;
		new_content->round = ((t_int_cont *)(list->content))->round;
		ft_lstadd_back(&new, ft_lstnew(new_content));
		list = list->next;
	}
	return (new);
}

int	push_to_list(char **splitted, t_list **lst)
{
	t_int_cont	*temp;

	while (splitted && *splitted)
	{
		temp = new_int(*splitted);
		if (!temp)
		{
			clear_arr(splitted);
			ft_lstclear(lst, free);
			exit(EXIT_FAILURE);
		}
		ft_lstadd_back(lst, ft_lstnew(temp));
		(void)*splitted++;
	}
	return (0);
}
