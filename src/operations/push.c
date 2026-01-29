#include "../../includes/push_swap.h"

void	ft_push(t_stack **src, t_stack **dst)
{
	t_stack	*temp_src;
	t_stack	*temp_dst;

	if (!*src)
		return ;
	temp_src = *src;
	temp_dst = *dst;
	*src = temp_src->next;
	*dst = temp_src;
	temp_src->next = temp_dst;
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_pustr_fd("pb\n", 1);
}