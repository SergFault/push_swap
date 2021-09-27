/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 23:22:36 by sergey            #+#    #+#             */
/*   Updated: 2021/09/27 23:25:51 by sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_handler(void)
{
	ft_putstr_fd("Error\n", STDOUT_FILENO);
	exit(EXIT_FAILURE);
}

void	free_set(t_set *set)
{
	if (!set)
		return ;
	if (set->int_lst)
		ft_lstclear(&set->int_lst, free);
	if (set->sorted)
		ft_lstclear(&set->sorted, free);
	if (set->stack_a)
		ft_lstclear(&set->stack_a, free);
	if (set->stack_b)
		ft_lstclear(&set->stack_b, free);
}

void	clear_arr(char **str_ar)
{
	int	c;

	c = 0;
	while (str_ar[c])
	{
		free(*str_ar);
		c++;
	}
	free(str_ar);
}
