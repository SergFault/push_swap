/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 23:24:02 by sergey            #+#    #+#             */
/*   Updated: 2021/09/27 23:24:02 by sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_space(char ch)
{
	if (ch == '\n' || ch == '\t' || ch == '\v'
		|| ch == ' ' || ch == '\r' || ch == '\f')
		return (1);
	return (0);
}

int	has_only_spaces(char *arg)
{
	while (arg && *arg)
	{
		if (!is_space(*arg))
			return (0);
		arg++;
	}
	return (1);
}

int	is_num(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

int	is_sign(char ch)
{
	if (ch == '-' || ch == '+')
		return (1);
	return (0);
}

int	has_number(char *str)
{
	while (str && *str)
	{
		if (is_num(*str))
			return (1);
		str++;
	}
	return (0);
}
