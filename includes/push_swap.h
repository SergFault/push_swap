#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

#include "../Libft/libft.h"

typedef struct s_int_cont
{
	int val;
	int index;
	int round;
} t_int_cont;

void ft_sx(t_list **stack_x, char stack_identity, int write);
void ft_ss(t_list **stack_a, t_list **stack_b, int write);
t_list *copy_stack(t_list *list);

#endif