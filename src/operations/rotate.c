#include "../../includes/push_swap.h"

static void	ft_rotate(t_stack **stack)
{
    t_stack	*tmp;
	t_stack *last;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	last = ft_last(*stack);
}

void	ft_ra(t_stack **stack_a)
{
	ft_rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}