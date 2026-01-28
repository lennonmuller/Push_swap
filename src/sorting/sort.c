#include "../../includes/push_swap.h"

int ft_is_sorted(t_stack *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

void    ft_sort_three(t_stack **stack_a)
{
    int	high;

	if (ft_is_sorted(*stack_a))
		return ;
	high = ft_find_high(*stack_a);
    if ((*stack_a)->value == high)
        ft_ra(stack_a);
}