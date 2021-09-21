#include "../includes/push_swap.h"

t_list *copy_stack(t_list *list)
{
	t_list *new;
	t_int_cont *new_content;

	new = NULL;
	while(list)
	{
		new_content = malloc(sizeof (t_int_cont));
		new_content->index = ((t_int_cont*)(list->content))->index;
		new_content->val = ((t_int_cont*)(list->content))->val;
		new_content->round = ((t_int_cont*)(list->content))->round;
		ft_lstadd_back(&new, ft_lstnew(new_content));
		list = list->next;
	}
	return new;
}