#include "../includes/push_swap.h"

#include <stdio.h>
int get_args(int argc, char **argv, t_list **lst)
{
    int c;
	int *temp;

    c = 1;
    if (argc < 2)
        return (-1);
    while (c < argc)
    {
		temp = malloc(sizeof (int));
		*temp = ft_atoi(argv[c]);
        ft_lstadd_back(lst, ft_lstnew(temp));
		c++;
    }
    return (0);
}

int main(int argc, char** argv)
{
    t_list *int_lst;

	int_lst = NULL;
	get_args(argc, argv, &int_lst);

	while(int_lst)
	{
		printf("%d\n", *((int*) int_lst->content) );
		int_lst = int_lst->next;
	}
}
