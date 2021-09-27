/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization_actions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 23:22:44 by sergey            #+#    #+#             */
/*   Updated: 2021/09/27 23:22:44 by sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra_or_rrr(t_set *set)
{
	if (set->stack_b && set->stack_a
		&& !is_next_eq(set->stack_b, set->s_data->next))
		perform(RRR, set);
	else
		perform(RRA, set);
}

int	try_swap_a(t_set *set)
{
	if (set->stack_a && set->stack_a->next && !needs_rotate_a(set)
		&& cont(set->stack_a->next)->index == set->s_data->next)
	{
		perform(SA, set);
		return (1);
	}
	return (0);
}

int	try_push_last_b(t_set *set)
{
	t_list	*iter;
	int		c;

	iter = set->stack_b;
	c = 0;
	while (iter && iter->next)
	{
		iter = iter->next;
		c++;
	}
	if (is_next_eq(iter, set->s_data->next) && c > 2)
	{
		perform(RRB, set);
		cont(set->stack_b)->sorted = 1;
		set->s_data->next++;
		perform(PA, set);
		perform(RA, set);
		return (1);
	}
	return (0);
}
