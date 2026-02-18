/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:45:05 by lmuler-f          #+#    #+#             */
/*   Updated: 2026/01/22 14:45:05 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void	ft_push_swap(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2 && !ft_is_sorted(*stack_a))
		ft_sa(stack_a);
	else if (size == 3 && !ft_is_sorted(*stack_a))
		ft_sort_three(stack_a);
	else if (size > 3 && !ft_is_sorted(*stack_a))
		ft_sort(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**str;

	str = NULL;
	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		str = ft_parsing_stack(av);
		ft_parsing(str);
		ft_fill_stack(str, &stack_a);
		free_arr(str);
		ft_index_stack(stack_a, ft_size(stack_a));
		ft_push_swap(&stack_a, &stack_b, ft_size(stack_a));
		ft_free_stack(&stack_a);
		ft_free_stack(&stack_b);
	}
	return (0);
}
