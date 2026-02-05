#include "../../includes/push_swap.h"

void	ft_index_stack(t_stack *stack_a, int size)
{
    t_stack	*current;
    t_stack	*high_node;
    int		max_value;

    while (size-- > 0)
    {
        current = stack_a;
        high_node = NULL;
        max_value = INT_MIN;
        while (current)
        {
            if (current->index == 0 && current->value >= max_value)
            {
                max_value = current->value;
                high_node = current;
            }
            current = current->next;
        }
        if (high_node)
            high_node->index = size;
    }
}