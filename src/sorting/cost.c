/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 17:48:47 by lmuler-f          #+#    #+#             */
/*   Updated: 2026/01/31 17:48:47 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b_tmp;
	int		a_size;
	int		b_size;

	a_size = ft_size(*stack_a);
	b_size = ft_size(*stack_b);
	b_tmp = *stack_b;
	while (b_tmp)
	{
		if (b_tmp->pos <= b_size / 2)
			b_tmp->cost_b = b_tmp->pos;
		else if (b_tmp->pos > b_size / 2)
			b_tmp->cost_b = (b_size - b_tmp->pos) * -1;
		if (b_tmp->target <= a_size / 2)
			b_tmp->cost_a = b_tmp->target;
		else if (b_tmp->target > a_size / 2)
			b_tmp->cost_a = (a_size - b_tmp->target) * -1;
		b_tmp = b_tmp->next;
	}
}