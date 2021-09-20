#include "../includes/push_swap.h"

int get_args(int argc, char **argv, t_list **lst)
{
    int c;

    c = 1;
    if (argc < 2)
        return (-1);
    while (c < arc)
    {
        ft_lstadd_back(ft_lstnew(ft_atoi(argv[c])));
    }
    return (0);
}

int main(int argc, char** argv)
{
    t_list *int_lst;

    int_lst = get_args(argc, argv, &int_lst);
}
