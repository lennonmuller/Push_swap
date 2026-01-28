#include "../../includes/push_swap.h"

int ft_find_high(t_stack *stack)
{
    int	high;

	high = INT_MIN;
	while (stack)
	{
		if (stack->value > high)
			high = stack->value;
		stack = stack->next;
	}
	return (high);
}