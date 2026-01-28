/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:00:31 by lmuler-f          #+#    #+#             */
/*   Updated: 2026/01/27 15:00:31 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void ft_swap(t_stack *stack)
{
    int tmp;

    if (!stack || !stack->next)
        return ;
    tmp = stack->value;
    stack->value = stack->next->value;
    stack->next->value = tmp;
    tmp = stack->index;
    stack->index = stack->next->index;
    stack->next->index = tmp;
}

void    ft_sa(t_stack **stack_a)
{
    ft_swap(*stack_a);
    ft_putstr_fd("sa\n", 1);
}

void    ft_sb(t_stack **stack_b)
{
    ft_swap(*stack_b);
    ft_putstr_fd("sb\n", 1);
}

void    ft_ss(t_stack **stack_a, t_stack **stack_b)
{
    ft_swap(*stack_a);
    ft_swap(*stack_b);
    ft_putstr_fd("ss\n", 1);
}