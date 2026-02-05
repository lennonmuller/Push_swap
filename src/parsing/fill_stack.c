/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:00:50 by lmuler-f          #+#    #+#             */
/*   Updated: 2026/02/05 13:00:50 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_fill_stack(char **str, t_stack **stack)
{
	long int	value;
	int			i;

	*stack = NULL;
	i = 0;
	while (str[i])
	{
		if (!ft_is_intfull(str[i]))
		{
			free_arr(str);
			ft_error();
			ft_free_stack(stack);
			exit(1);
		}
		value = ft_atol(str[i]);
		ft_lst_add_back(stack, ft_lst_new((int)value));
		i++;
	}
}
