#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

#include "../Libft/libft.h"
#include <stddef.h>
#include <limits.h>
#define CONT(x) ((t_int_cont *)x->content)
#define PRINT print_stacks(set->stack_a, set->stack_b);

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
int has_lower(t_list *stack, int val);
int has_bigger(t_list *stack, int val);
int lo_e(t_list *stack, int val);
int bigger_e(t_list *stack, int val);
int is_next_eq(t_list *stack, int val);
void to_sorted(char location, t_set *set);
int is_cur(t_list *stack, int chunk);
int has_sorted (t_list *stack);
int needs_rotate_a(t_set *set);
t_int_cont *new_int(char *str_int);
void init_set(t_set *set);


#endif