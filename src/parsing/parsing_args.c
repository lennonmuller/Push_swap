/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 20:30:30 by lmuler-f          #+#    #+#             */
/*   Updated: 2026/01/15 20:30:30 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_is_intfull(char *str)
{
	long	num;

	num = ft_atol(str);
	if (num > 2147483647 || num < -2174483648)
		return (0);
	return (1);
}

static int	ft_valid_args(char **args)
{
    int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		if (is_sign(args[i][j]))
		{
			j++;
			if(!args[i][j])
				return (0);
		}
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
				return (0);
			j++;
		}
		if (!ft_is_intfull(args[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_duplicated(char **args)
{
	int	i;
	int	j;

	i = 0;
	while(args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atol(args[i]) == ft_atol(args[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_parsing(char **args)
{
	if(!ft_valid_args(args))
	{
		free_arr(args);
		ft_error();
		exit(1);
	}
	if (!ft_is_duplicated(args))
	{
		free_arr(args);
		ft_error();
		exit(1);
	}
}