#include "../includes/push_swap.h"

#include <stdio.h>


t_int_cont *new_int(char *str_int)
{
	int i;
	t_int_cont *cont;

	i = ft_atoi(str_int);
	cont = (t_int_cont *) malloc(sizeof(t_int_cont));
	cont->val = i;
	cont->index = 0;
	cont->round = 0;
	cont->sorted = 0;
	return cont;
}

void print_lst(t_list *lst)
{
	while(lst)
	{
		printf("index %d\n",  ((t_int_cont *) lst->content)->index );
		printf("round %d\n",  ((t_int_cont *) lst->content)->round );
		printf("val %d\n",  ((t_int_cont *) lst->content)->val);
		printf("\n\n");
		lst = lst->next;
	}
}

void print_stacks(t_list *stack_a, t_list *stack_b)
{
	printf("stack A\t\t\t\t\t\t\t\tstack B\n");
	while(stack_a || stack_b)
	{
		if (stack_a) {
			printf("index %d \t", ((t_int_cont *) stack_a->content)->index);
			printf("round %d \t", ((t_int_cont *) stack_a->content)->round);
			printf("val %d \t", ((t_int_cont *) stack_a->content)->val);
			printf("sorted %d \t|", ((t_int_cont *) stack_a->content)->sorted);
			stack_a = stack_a->next;
		} else
		{
			printf("NULL      \tNULL      \tNULL       \tNULL  \t|");
		}
		printf("\t\t");
		if (stack_b) {
			printf("index %d \t", ((t_int_cont *) stack_b->content)->index);
			printf("round %d \t", ((t_int_cont *) stack_b->content)->round);
			printf("val %d \t", ((t_int_cont *) stack_b->content)->val);
			printf("sorted %d \t|", ((t_int_cont *) stack_b->content)->sorted);
			stack_b = stack_b->next;
		} else
		{
			printf("NULL      \tNULL      \tNULL       \tNULL  \t|");
		}
		printf("\n");
	}
}

int get_args(int argc, char **argv, t_list **lst)
{
    int c;
	t_int_cont *temp;

    c = 1;
    if (argc < 2)
        return (-1);
    while (c < argc)
    {
		temp = new_int(argv[c]);
        ft_lstadd_back(lst, ft_lstnew(temp));
		c++;
    }
    return (0);
}

//int sort(t_list **stack_a_ptr, t_list **stack_b_ptr, t_list *sorted)
//{
//	int max;
//	int c;
//	t_list *stack_a;
//	t_list *stack_b;
//
//	stack_a = *stack_a_ptr;
//	stack_b = *stack_b_ptr;
//
//	c = 0;
//	max = 0;
//	while (sorted)
//	{
//		sorted = sorted->next;
//		max++;
//	}
//
//	while(stack_a)
//	{
//		if (((t_int_cont *) (stack_a->content))->index == c)
//		{
//			ft_px(&stack_a, &stack_b, 'b', 1);
//			c++;
//		}
//		else
//		{
//			ft_rx(&stack_a,'a', 1);
//		}
//	}
//	c = 0;
//	while(c < max)
//	{
//		ft_px(&stack_a, &stack_b, 'a', 1);
//		c++;
//	}
//	*stack_a_ptr = stack_a;
//	*stack_b_ptr = stack_b;
//	return (1);
//}

void init_set(t_set *set)
{
	set->s_data->next = 0;
	set->s_data->max = 0;
	set->s_data->mid = 0;
	set->s_data->min = 0;
	set->s_data->size = 0;
	set->s_data->round = 1;
	set->int_lst = NULL;
	set->sorted = NULL;
	set->stack_a = NULL;
	set->stack_b = NULL;
}


int small_sort_b(t_list **stack_b)
{
	int val1;
	int val2;
	int val3;

	val1 = ((t_int_cont *)((*stack_b)->content))->index;
	val2 = ((t_int_cont *)((*stack_b)->next->content))->index;
	val3 = ((t_int_cont *)((*stack_b)->next->next->content))->index;
	if (val1 < val3 && val3 < val2)
	{
		ft_sx(stack_b, 'b', 1);
		ft_rx(stack_b, 'b', 1);
	} else if (val2 < val1 && val1 < val3)
	{
		ft_sx(stack_b, 'b', 1);
	}
	else if  (val3 < val1 && val1 < val2)
	{
		ft_rrx(stack_b, 'b', 1);
	}
	else if  (val3 < val2 && val2 < val1)
	{
		ft_sx(stack_b, 'b', 1);
		ft_rrx(stack_b, 'b', 1);
	}
	else if  (val2 < val3 && val3 < val1)
	{
		ft_rx(stack_b, 'b', 1);
	}
	return (1);
}

int get_stack_data(t_set *set, t_list *stack)
{
	int min;
	int max;

	min = 0;
	max = 0;
	set->s_data->size = 0;
	if (stack) {
		min = ((t_int_cont *) stack->content)->index;
		max = ((t_int_cont *) stack->content)->index;
	}
	while(stack)
	{
		if (((t_int_cont *)stack->content)->index > max)
			max = ((t_int_cont *)stack->content)->index;
		if (((t_int_cont *)stack->content)->index < min)
			min = ((t_int_cont *)stack->content)->index;
		stack = stack->next;
		set->s_data->size++;
	}
	set->s_data->max = max;
	set->s_data->min = min;
	set->s_data->mid = min + ((max - min) / 2);
	return (1);
}

int get_stack_data_round(t_set *set, t_list *stack)
{
	int min;
	int max;
	int round;

	round = (((t_int_cont *)stack->content)->round);
	set->s_data->size = 0;
	min = ((t_int_cont *)stack->content)->index;
	max = ((t_int_cont *)stack->content)->index;
	while(stack)
	{
		if ((((t_int_cont *)stack->content)->round == round) &&
		!(((t_int_cont *)stack->content)->sorted))
		{
			if (((t_int_cont *) stack->content)->index > max)
				max = ((t_int_cont *) stack->content)->index;
			if (((t_int_cont *) stack->content)->index < min)
				min = ((t_int_cont *) stack->content)->index;
			set->s_data->size++;
		}
		stack = stack->next;
	}
	set->s_data->max = max;
	set->s_data->min = min;
	set->s_data->mid = min + ((max - min) / 2);
	return (1);
}


int all_sorted(t_list **stack_a)
{
	t_list *iter;

	iter = *stack_a;
	while (iter)
	{
		if ((((t_int_cont *) (iter->content))->sorted) == 0)
			return (0);
		iter = iter->next;
	}
	return (1);
}

int has_sorted_elem(t_list **stack_a)
{
	t_list *iter_a;

	iter_a = *stack_a;
	while(iter_a)
	{
		if (((t_int_cont *)(iter_a->content))->sorted)
			return (1);
		iter_a = iter_a->next;
	}
	return (0);
}

int needs_rotate(t_list **stack_a)
{
	t_list *iter_a;

	iter_a = *stack_a;

	if (all_sorted(stack_a))
		return (0);

	if (has_sorted_elem(&iter_a))
	{
//		print_stacks(*stack_a, *stack_a);
		while (iter_a->next)
			iter_a = iter_a->next;

		if ((!(((t_int_cont *) (iter_a->content))->sorted)) ||
		((((t_int_cont *) ((*stack_a)->content))->sorted)))
			return (1);
	}
	return (0);
}
int rotate_direction(t_list **stack_a) {
	t_list *iter;
	int size;
	int pos;

	size = 0;
	pos = 0;
	iter = *stack_a;

	while (iter)
	{
		if ((((t_int_cont *) (iter->content))->sorted))
			pos = size;
		iter = iter->next;
		size++;
	}
	if ((size - pos) > pos)
		return (1);
	return (0);
}


int rotate_sorted_bottom(t_list **stack_a, t_list **stack_b, t_set *set)
{

	int rotate;
	(void) stack_b;
	(void) set;

	rotate = rotate_direction(stack_a);
	while (needs_rotate(stack_a))
	{
		if (rotate)
		{
			if (((t_int_cont *)(*stack_b)->content)->index !=
			set->s_data->next)
			{
				ft_rr(stack_a, stack_b, 1);
			}else
			{
				ft_rx(stack_a, 'a', 1);
			}
		}
		else
		{
			if (*stack_b && (((t_int_cont *)(*stack_b)->content)->index !=
				set->s_data->next))
			{
				ft_rrr(stack_a, stack_b, 1);
			}else
			{
				ft_rrx(stack_a, 'a', 1);
			}
		}
	}
	return (1);
}

void move_sorted_a(t_set *set)
{
	((t_int_cont *) set->stack_a->content)->sorted = 1;
	ft_rx(&set->stack_a, 'a', 1);
	set->s_data->next++;
}

void move_sorted_b(t_set *set)
{
	((t_int_cont *) set->stack_b->content)->sorted = 1;
	ft_px(&set->stack_a, &set->stack_b, 'a', 1);
	ft_rx(&set->stack_a, 'a', 1);
	set->s_data->next++;
}

int try_first_a(t_set *set) {
	int changes;
	int ret;

	ret = 0;
	changes = 1;
	while (!(needs_rotate(&set->stack_a)) && changes) {
		changes = 0;
		if ((((t_int_cont *) set->stack_a->content)->index) ==
			set->s_data->next) {
//			ft_putstr_fd("try_first", 1);
//			print_stacks(set->stack_a, set->stack_b);
			move_sorted_a(set);
			changes = 1;
			ret++;
//		}else if ((((t_int_cont *) set->stack_a->next->content)->index) ==
//			set->s_data->next) {
//			sort_two(&set->stack_a, 'a');
////			print_stacks(set->stack_a, set->stack_b);
//			changes = 1;
		}
	}
	return (ret);
}

int try_first_b(t_set *set)
{
	int changes;
	int ret;

	ret = 0;
	changes = 1;
	while (changes)
	{
		changes = 0;
		if (set->stack_b && (((t_int_cont *) set->stack_b->content)->index) ==
			set->s_data->next) {
//			ft_putstr_fd("HERE\n", 1);
//			ft_putstr_fd("try first b\n", 1);
			move_sorted_b(set);
			changes = 1;
			ret++;
		}
	}
	return (ret);
}

int try_last_b(t_set *set)
{
	int changes;
	int ret;
	t_list *iter;

	iter = set->stack_b;
	while(iter && iter->next)
	{
		iter = iter->next;
	}

	ret = 0;
	changes = 1;
	while (changes)
	{
		changes = 0;
		if (iter && (((t_int_cont *) iter->content)->index) ==
							set->s_data->next) {
			print_stacks(set->stack_a, set->stack_b);
			ft_putstr_fd("HERE\n", 1);
			ft_putstr_fd("try last b\n", 1);
			ft_rrx(&set->stack_b, 'b', 1);
			move_sorted_b(set);
			changes = 1;
			ret++;
		}
	}
	return (ret);
}

int has_lo_eq(t_list *stack, int i, int size_left)
{
	while (stack && size_left--)
	{
		if (((t_int_cont *)(stack->content))->index <= i) {
			return (1);
		}
		stack = stack->next;
	}
//	print_stacks(stack, stack);
	return (0);
}

int has_bigger(t_list *stack, int i)
{
	while (stack)
	{
		if (((t_int_cont *)(stack->content))->index >= i)
		{
			return (1);
		}
		stack = stack->next;
	}
	return (0);
}

int do_swap(t_set *set)
{
	int changes;
	int ret;

	ret = 0;
	changes = 1;
	while (changes)
	{
		changes = 0;
		if (set->stack_a && (((t_int_cont *) set->stack_a->next->content)
		->index) == set->s_data->next)
		{
			//ft_putstr_fd("swap\n", 1);
			ft_sx(&set->stack_a, 'a', 1);
			changes = try_first_a(set);
			ret += changes;
		}
	}
	return (ret);
}

int first_split(t_set *set){

	get_stack_data_round(set, set->stack_a);

	while(has_lo_eq(set->stack_a, set->s_data->mid, 100))
	{
		if (((((t_int_cont *)set->stack_a->content)->index) <=
			  set->s_data->mid))
		{
			ft_px(&set->stack_a, &set->stack_b, 'b', 1);
		}
		else
		{
			ft_rx(&set->stack_a, 'a', 1);
		}
	}
	return (1);
}

int split_to_b(t_set *set){
	int size;
	int curr_ch;


	if (!(needs_rotate(&set->stack_a)))
		do_swap(set);
	try_first_a(set);

	get_stack_data_round(set, set->stack_a);
	curr_ch =  ((t_int_cont *) (set->stack_a->content))->round;
	size = set->s_data->size;
	while(size && !(((t_int_cont *)set->stack_a->content)->sorted)
			&& curr_ch == (((t_int_cont *)set->stack_a->content)->round))
			//&& has_lo_eq(set->stack_a, set->s_data->mid, size))
	{
			if (!(needs_rotate(&set->stack_a)))
				size -= do_swap(set);
			size -= try_first_a(set);
			if (size <= 0)
				break;
//			if ((((((t_int_cont *)set->stack_a->content)->index) <=
//				set->s_data->mid)) &&
//				(((((t_int_cont *)set->stack_a->content)->sorted) == 0)))

//		if ((((t_int_cont *)set->stack_a->content)->sorted) == 0) {
//			if (curr_ch == (((t_int_cont *) set->stack_a->content)->round)) {
//				if ((((((t_int_cont *) set->stack_a->content)->index) <=
//					  set->s_data->mid)))
//					ft_px(&set->stack_a, &set->stack_b, 'b', 1);
//				else
//					ft_rx(&set->stack_a, 'a', 1);
//			}
//		}
//		if (size <= 1)
//			break;

		if ((((t_int_cont *)set->stack_a->content)->sorted) == 0)
		{
			if (curr_ch == 0)
			{
				if ((((((t_int_cont *)set->stack_a->content)->index) <=
				set->s_data->mid)))
					ft_px(&set->stack_a, &set->stack_b, 'b', 1);
				else
					ft_rx(&set->stack_a, 'a', 1);
			}
			else if (curr_ch == (((t_int_cont *)set->stack_a->content)->round))
			{
				ft_px(&set->stack_a, &set->stack_b, 'b', 1);
			}
		}
//				if (size <= 1)
//			break;

		size--;
	}
	rotate_sorted_bottom(&set->stack_a, &set->stack_b, set);
	return (1);
}

int split_to_a(t_set *set)
{
	int size;



	try_first_b(set);
//	try_last_b(set);
	get_stack_data(set, set->stack_b);
	size = set->s_data->size;

	if (size == 3)
		small_sort_b(&set->stack_b);

	while(set->stack_b) // && size)
	{

		size -= try_first_b(set);
//		size -= try_last_b(set);

		if (!(has_bigger(set->stack_b, set->s_data->mid))) {
//			ft_putchar_fd(set->s_data->mid + '0', 1);
//			ft_putchar_fd(set->s_data->mid + '\n', 1);
//			ft_putstr_fd("hasn`t bigger value\n", 1);
//			print_stacks(set->stack_a, set->stack_b);
			break;
		}
		if (set->stack_b && (((t_int_cont *)set->stack_b->content)->index) >=
		set->s_data->mid)
		{
//			print_stacks(set->stack_a, set->stack_b);
			((t_int_cont *) set->stack_b->content)->round = set->s_data->round;
			ft_px(&set->stack_a, &set->stack_b, 'a', 1);
		}
		else
		{

//			print_stacks(set->stack_a, set->stack_b);
//			ft_putstr_fd("HERE\n", 1);

				ft_rx(&set->stack_b, 'b', 1);
		}
		//size--;
	}
	set->s_data->round++;
	return (1);
}

int is_sorted(t_list *stack_a )
{
	while(stack_a)
	{
		if (!((t_int_cont *)stack_a->content)->sorted)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int sort(t_set *set)
{
//	first_split(set);
	while (!(is_sorted(set->stack_a)) || (set->stack_b))
	{
		while (set->stack_b) {

//			ft_putstr_fd("split to a\n", 1);
//			print_stacks(set->stack_a, set->stack_b);

			split_to_a(set);
		}

//		print_stacks(set->stack_a, set->stack_b);
//		ft_putstr_fd("split to b\n", 1);

		split_to_b(set);
	}
//	print_stacks(set->stack_a, set->stack_b);
	return 0;
}

int main(int argc, char** argv)
{
	t_set set;

	init_set(&set);

	get_args(argc, argv, &set.int_lst);
	set.sorted = copy_stack(set.int_lst);
	ft_sort(set.sorted);
//	print_lst(sorted);
	set.stack_a = copy_stack(set.int_lst);
	index_stack(set.stack_a, set.sorted);
//	print_stacks(stack_a, stack_b);
	sort(&set);
//	print_stacks(stack_a, stack_b);
//	ft_rrx(&stack_a, 'a', 1);
//	print_stacks(stack_a, stack_b);
//
//	ft_rrx(&stack_a, 'a', 1);
//	print_stacks(stack_a, stack_b);
//
//	ft_rrx(&stack_a, 'a', 1);
//	print_stacks(stack_a, stack_b);
//
//	ft_rrx(&stack_b, 'b', 1);
//	print_stacks(stack_a, stack_b);

	//ft_sx(&int_lst, 'a', 1);
	//print_lst(int_lst);

}
