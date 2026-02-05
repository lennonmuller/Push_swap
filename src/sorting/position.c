/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 17:48:58 by lmuler-f          #+#    #+#             */
/*   Updated: 2026/01/31 17:48:58 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

int	ft_find_high(t_stack *stack)
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

int	ft_lowest_idx_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_i;
	int		lowest_p;

	tmp = *stack;
	lowest_i = INT_MAX;
	ft_position(stack);
	lowest_p = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_i)
		{
			lowest_i = tmp->index;
			lowest_p = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_p);
}

int	ft_target(t_stack **stack_a, int b_index, int target_index,
				int target_pos)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index > b_index && tmp->index < target_index)
		{
			target_index = tmp->index;
			target_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (target_index != INT_MAX)
		return (target_pos);
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index < target_index)
		{
			target_index = tmp->index;
			target_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (target_pos);
}

void	ft_assign_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		target;

	tmp = *stack_b;
	target = 0;
	ft_position(stack_a);
	ft_position(stack_b);
	while (tmp)
	{
		target = ft_target(stack_a, tmp->index, INT_MAX, target);
		tmp->target = target;
		tmp = tmp->next;
	}
}
