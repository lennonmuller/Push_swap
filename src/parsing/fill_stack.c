#include "../../includes/push_swap.h"

void	ft_fill_stack(char **str, t_stack **stack)
{
    long int	value;
    int			i;

    *stack = NULL;
    i = 0;
    while (str[i])
    {
        value = ft_atol(str[i]);
        if (!ft_is_intfull(value))
        {
            free_arr(str);
            ft_error();
            ft_free_stack(stack);
            exit(1);
        }
        ft_lst_add_back(stack, ft_lst_new((int)value));
        i++;
    }
}