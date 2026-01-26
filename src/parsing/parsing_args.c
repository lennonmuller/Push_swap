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

static int	ft_valid_args(char **av)
{
    int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		if (is_sign(av[i][j]))
		{
			j++;
			if(!av[i][j])
				return (0);
		}
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		if (!ft_is_intfull(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_duplicated(char **av)
{
	int	i;
	int	j;

	i = 0;
	while(av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atol(av[i]) == ft_atol(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_parsing(char **av)
{
	if(!ft_valid_args(av))
	{
		free_arr(av);
		ft_error();
		exit(1);
	}
	if (!ft_is_duplicated(av))
	{
		free_arr(av);
		ft_error();
		exit(1);
	}
}