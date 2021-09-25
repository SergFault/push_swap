#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

#include "../Libft/libft.h"
#include <stddef.h>
#include <limits.h>
#define CONT(x) ((t_int_cont *)x->content)

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

#define SA 1
#define SB 2
#define SS 3
#define RA 4
#define RB 5
#define RRA 6
#define RRB 7
#define RRR 8
#define PA 9
#define PB 10
#define RR 11

void perform(int op, t_set *set);
t_list *copy_stack(t_list *list);
void index_stack(t_list *stack, t_list *sorted);
void ft_sort(t_list *list);

#endif