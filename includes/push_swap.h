#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

#include "../Libft/libft.h"
#include <stddef.h>
#include <limits.h>

typedef struct s_data
{
	int next;
	int round;
	int min;
	int mid;
	int max;
	int size;
} t_data;

typedef struct s_set{
	t_data *s_data;
	t_list *int_lst;
	t_list *sorted;
	t_list *stack_a;
	t_list *stack_b;
} t_set;

typedef struct s_int_cont
{
	int val;
	int index;
	int round;
	int sorted;
} t_int_cont;

void ft_sx(t_list **stack_x, char stack_identity, int write);
void ft_ss(t_list **stack_a, t_list **stack_b, int write);
void ft_rx (t_list **stack, char stack_identity, int write);
void ft_rrx (t_list **stack, char stack_identity, int write);
void ft_px(t_list **stack_a, t_list **stack_b, char push_to, int write);
void	ft_rr(t_list **stack_a, t_list **stack_b, int write);
void	ft_rrr(t_list **stack_a, t_list **stack_b, int write);
t_list *copy_stack(t_list *list);
void index_stack(t_list *stack, t_list *sorted);
void ft_sort(t_list *list);

#endif