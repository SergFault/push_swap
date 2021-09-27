/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 23:20:38 by sergey            #+#    #+#             */
/*   Updated: 2021/09/27 23:20:44 by sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	free_fail(char **str_a, int c)
{
	int	counter;

	counter = 0;
	while (counter < c)
	{
		free(str_a[c]);
		counter++;
	}
	free(str_a);
	return (0);
}

static size_t	ft_datasnaps(const char *str)
{
	size_t	c;

	c = 0;
	while (*str)
	{
		if (is_space(*str))
			while (is_space(*str) && *str)
				str++;
		else
		{
			c++;
			while (!is_space(*str) && *str)
				str++;
		}
	}
	return (c);
}

static int	ft_parse(char **str, const char *src, size_t d_snaps)
{
	size_t	size;
	size_t	str_n;

	str_n = 0;
	while (str_n < d_snaps)
	{
		size = 0;
		while (is_space(*src) && *src)
			src++;
		while (!(is_space(*src) && *src))
		{
			src++;
			size++;
		}
		str[str_n] = (char *)malloc(sizeof(char) * (size + 1));
		if (!(str[str_n]))
			return (free_fail(str, str_n));
		src -= size;
		ft_strlcpy(str[str_n], src, size + 1);
		src += size;
		str_n++;
	}
	return (1);
}

char	**split_arg(char const *s)
{
	char	**ret;
	size_t	data_snaps;

	if (!s)
		return (NULL);
	data_snaps = ft_datasnaps(s);
	ret = (char **)malloc(sizeof(char *) * (data_snaps + 1));
	if (!(ret))
		return (NULL);
	ft_parse(ret, s, data_snaps);
	ret[data_snaps] = NULL;
	return (ret);
}
