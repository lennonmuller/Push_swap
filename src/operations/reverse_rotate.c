/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:57:41 by lmuler-f          #+#    #+#             */
/*   Updated: 2026/02/05 12:57:41 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*before_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = ft_last(*stack);
	before_last = ft_before_last(*stack);
	tmp = *stack;
	*stack = last;
	(*stack)->next = tmp;
	before_last->next = NULL;
}

void	ft_rra(t_stack **stack_a)
{
	ft_reverse_rotate(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_stack **stack_b)
{
	ft_reverse_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
