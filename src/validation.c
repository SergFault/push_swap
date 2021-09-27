#include "../includes/push_swap.h"

int	check_repeat(t_list *stack)
{
	while (stack && stack->next)
	{
		if (cont(stack)->val == cont(stack->next)->val)
			return (1);
		stack = stack->next;
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
