/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_processor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 23:23:16 by sergey            #+#    #+#             */
/*   Updated: 2021/09/28 14:04:31 by sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sx(t_list **stack_x, char stack_identity, int write)
{
	void	*temp;
	t_list	*stack;

	if (!stack_x || !*stack_x || !(*stack_x)->next)
		return ;
	stack = *stack_x;
	temp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp;
	if (write)
	{
		ft_putchar_fd('s', STDOUT_FILENO);
		ft_putchar_fd(stack_identity, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
}

void	ft_px(t_list **stack_a, t_list **stack_b, char push_to, int write)
{
	t_list	*temp;

	if (push_to == 'a' && *stack_b)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		ft_lstadd_front(stack_a, temp);
	}
	else if (push_to == 'b' && *stack_a)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		ft_lstadd_front(stack_b, temp);
	}
	if (write)
	{
		ft_putstr_fd("p", STDOUT_FILENO);
		if (push_to == 'a')
			ft_putstr_fd("a\n", STDOUT_FILENO);
		else
			ft_putstr_fd("b\n", STDOUT_FILENO);
	}
}

void	ft_rx(t_list **stack, char stack_identity, int write)
{
	t_list	*last;
	t_list	*temp;

	last = *stack;
	if ((*stack) == NULL)
		return ;
	while (last->next)
		last = last->next;
	if (last != *stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		temp->next = NULL;
		ft_lstadd_back(stack, temp);
		if (write)
		{
			ft_putchar_fd('r', STDOUT_FILENO);
			ft_putchar_fd(stack_identity, STDOUT_FILENO);
			ft_putchar_fd('\n', STDOUT_FILENO);
		}
	}
}

void	ft_rrx(t_list **stack, char stack_identity, int write)
{
	t_list	*last;

	last = *stack;
	if ((*stack) == NULL)
		return ;
	while (last->next)
		last = last->next;
	if (last != *stack)
	{
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = NULL;
		ft_lstadd_front(stack, last);
		if (write)
		{
			ft_putstr_fd("rr", STDOUT_FILENO);
			ft_putchar_fd(stack_identity, STDOUT_FILENO);
			ft_putchar_fd('\n', STDOUT_FILENO);
		}
	}
}

void	ft_rr(t_list **stack_a, t_list **stack_b, int write)
{
	ft_rx(stack_a, 'a', 0);
	ft_rx(stack_b, 'b', 0);
	if (write)
		ft_putstr_fd("rr\n", STDOUT_FILENO);
}
