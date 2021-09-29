/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 23:22:14 by sergey            #+#    #+#             */
/*   Updated: 2021/09/29 13:58:52 by sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_int_cont	*new_int(char *str_int)
{
	int			i;
	t_int_cont	*cont;

	i = ft_atoi(str_int);
	cont = (t_int_cont *) malloc(sizeof(t_int_cont));
	if (cont == NULL)
		return (NULL);
	cont->val = i;
	cont->index = 0;
	cont->round = 0;
	cont->sorted = 0;
	return (cont);
}

void	init_set(t_set *set)
{
	set->s_data->next = 0;
	set->s_data->max = 0;
	set->s_data->mid = 0;
	set->s_data->min = 0;
	set->s_data->size = 0;
	set->s_data->round_c = 1;
	set->int_lst = NULL;
	set->sorted = NULL;
	set->stack_a = NULL;
	set->stack_b = NULL;
}
