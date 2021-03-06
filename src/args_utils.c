/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 23:20:18 by sergey            #+#    #+#             */
/*   Updated: 2021/09/29 14:34:02 by sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_args(int argc, char **argv, t_list **lst)
{
	int		c;
	char	**splitted;

	splitted = NULL;
	c = 1;
	if (argc < 2)
		exit(EXIT_FAILURE);
	while (c < argc)
	{
		if (check_arg(c, argv))
			splitted = split_arg(argv[c]);
		else
			error_handler();
		push_to_list(splitted, lst);
		c++;
	}
	return (0);
}
