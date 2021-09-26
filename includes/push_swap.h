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
	int round_c;
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

void		perform(int op, t_set *set);
t_list		*copy_stack(t_list *list);
void		index_stack(t_list *stack, t_list *sorted);
void		ft_sort(t_list *list);
int			has_lower(t_list *stack, int val);
int			has_bigger(t_list *stack, int val);
int			lo_e(t_list *stack, int val);
int			bigger_e(t_list *stack, int val);
int			is_next_eq(t_list *stack, int val);
void		to_sorted(char location, t_set *set);
int			is_chunk(t_list *stack, int chunk);
int			has_sorted (t_list *stack);
int			needs_rotate_a(t_set *set);
t_int_cont	*new_int(char *str_int);
void		init_set(t_set *set);
int			small_sort_b(t_list **stack_b);
int			get_stack_size(t_list *stack);
int			small_sort_desc(t_list **stack_b);
void		ft_sx(t_list **stack_x, char stack_identity, int write);
void		ft_px(t_list **stack_a, t_list **stack_b, char push_to, int write);
void		ft_ss(t_list **stack_a, t_list **stack_b, int write);
void		ft_rx (t_list **stack, char stack_identity, int write);
void		ft_rrx (t_list **stack, char stack_identity, int write);
void		ft_rrr(t_list **stack_a, t_list **stack_b, int write);
void		ft_rr(t_list **stack_a, t_list **stack_b, int write);
int			is_space(char ch);
char		**split_arg(char const *s);
int			small_sort(t_set *set);
int			default_sort(t_set *set);
int			first_split(t_set *set);
int			four_sort(t_set *set);
int			five_sort(t_set *set);
int			count_elements(t_list *stack);
int			has_only_spaces(char *arg);
int			is_num(char ch);
int			is_sign(char ch);
int			has_number(char *str);
int			valid_str_ints(char *str);
int			check_arg(int argc, char **argv);
void		clear_arr(char **str_ar);
int			push_to_list(char **splitted,  t_list **lst);
void		error_handler();
int			get_args(int argc, char **argv, t_list **lst);
int			check_repeat(t_list *stack);
int			is_sorted(t_list *stack);

#endif