/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 23:24:11 by sergey            #+#    #+#             */
/*   Updated: 2021/09/27 23:35:22 by sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_repeat(t_list *stack)
{
	t_list	*start;
	t_list	*iter;

	iter = stack;
	start = stack;
	stack = stack->next;
	while (stack && stack->next)
	{
		while (iter != stack)
		{
			if (cont(iter)->val == cont(stack->next)->val)
				return (1);
			iter = iter->next;
		}
		stack = stack->next;
		iter = start;
	}
	return (0);
}

int	valid_str_ints(char *str)
{
	int	was_sign;
	int	was_num;

	was_sign = 0;
	was_num = 0;
	while (*str)
	{
		if (is_num(*str))
			was_num = 1;
		else if (is_sign(*str) && !was_sign && !was_num)
			was_sign = 1;
		else if (is_space(*str) && !(was_sign && !was_num))
		{
			was_num = 0;
			was_sign = 0;
		}
		else
			return (0);
		str++;
	}
	return (1);
}

int	check_arg(int argc, char **argv)
{
	if (has_only_spaces(argv[argc]))
		return (1);
	if (!has_number(argv[argc]))
		return (0);
	if (valid_str_ints(argv[argc]))
		return (1);
	return (0);
}
