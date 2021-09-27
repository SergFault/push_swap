/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 23:23:09 by sergey            #+#    #+#             */
/*   Updated: 2021/09/27 23:23:09 by sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	index_stack(t_list *stack, t_list *sorted)
{
	int		index;
	t_list	*iter;

	iter = stack;
	index = 0;
	while (sorted)
	{
		while (iter)
		{
			if (((t_int_cont *)iter->content)->val
				== (((t_int_cont *)sorted->content)->val))
			{
				((t_int_cont *)iter->content)->index = index++;
				break ;
			}
			iter = iter->next;
		}
		iter = stack;
		sorted = sorted->next;
	}
}

int	is_last_sorted(t_list *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		stack = stack->next;
	}
	if (cont(stack)->sorted)
		return (1);
	return (0);
}

int	find_pos(t_list *stack, int index)
{
	int	c;

	c = 0;
	while (stack)
	{
		if (cont(stack)->index == index)
			return (c);
		stack = stack->next;
		c++;
	}
	return (c);
}

int	find_min_index(t_list *stack)
{
	int	min_index;

	min_index = 0;
	if (stack)
		min_index = cont(stack)->index;
	while (stack)
	{
		if (cont(stack)->index < min_index)
			min_index = cont(stack)->index;
		stack = stack->next;
	}
	return (min_index);
}

void	get_stack_data_round(t_set *set, t_list *stack)
{
	int	min;
	int	max;
	int	round;

	round = (((t_int_cont *)stack->content)->round);
	set->s_data->size = 0;
	min = ((t_int_cont *)stack->content)->index;
	max = ((t_int_cont *)stack->content)->index;
	while (stack)
	{
		if ((((t_int_cont *)stack->content)->round == round)
			&& !(((t_int_cont *)stack->content)->sorted))
		{
			if (((t_int_cont *) stack->content)->index > max)
				max = ((t_int_cont *) stack->content)->index;
			if (((t_int_cont *) stack->content)->index < min)
				min = ((t_int_cont *) stack->content)->index;
			set->s_data->size++;
		}
		stack = stack->next;
	}
	set->s_data->max = max;
	set->s_data->min = min;
	set->s_data->mid = min + ((max - min) / 2);
}
