/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 04:15:07 by lmuler-f          #+#    #+#             */
/*   Updated: 2026/01/29 04:15:07 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	ft_push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	i;
	int	is_pushed;

	size = ft_size(*stack_a);
	is_pushed = 0;
	i = 0;
	while (size > 6 && i < size && is_pushed < size / 2)
	{
		if ((*stack_a)->index <= size / 2)
		{
			ft_pb(stack_a, stack_b);
			is_pushed++;
		}
		else
			ft_ra(stack_a);
		i++;
	}
	while (size - is_pushed > 3)
	{
		ft_pb(stack_a, stack_b);
		is_pushed++;
	}
}

void	ft_sort_three(t_stack **stack_a)
{
    int	high;

	if (ft_is_sorted(*stack_a))
		return ;
	high = ft_find_high(*stack_a);
    if ((*stack_a)->value == high)
        ft_ra(stack_a);
	else if ((*stack_a)->next->value == high)
		ft_rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		ft_sa(stack_a);
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_to_b(stack_a, stack_b);
	ft_sort_three(stack_a);
}