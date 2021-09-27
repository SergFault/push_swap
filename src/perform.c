/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 23:22:54 by sergey            #+#    #+#             */
/*   Updated: 2021/09/27 23:22:54 by sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	perform(int op, t_set *set)
{
	if (op == SA)
		ft_sx(&set->stack_a, 'a', 1);
	 else if (op == SB)
		ft_sx(&set->stack_b, 'b', 1);
	else if (op == SS)
		ft_ss(&set->stack_a, &set->stack_b, 1);
	else if (op == RA)
		ft_rx(&set->stack_a, 'a', 1);
	else if (op == RB)
		ft_rx(&set->stack_b, 'b', 1);
	else if (op == RR)
		ft_rr(&set->stack_a, &set->stack_b, 1);
	else if (op == RRA)
		ft_rrx(&set->stack_a, 'a', 1);
	else if (op == RRB)
		ft_rrx(&set->stack_b, 'b', 1);
	else if (op == RRR)
		ft_rrr(&set->stack_a, &set->stack_b, 1);
	else if (op == PA)
		ft_px(&set->stack_a, &set->stack_b, 'a', 1);
	else if (op == PB)
		ft_px(&set->stack_a, &set->stack_b, 'b', 1);
}
