/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 20:30:49 by lmuler-f          #+#    #+#             */
/*   Updated: 2026/01/15 20:30:49 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
    int				value;
	int				index;
	int				pos;
	int				target;
	int				cost_a;
	int				cost_b;
	struct s_stack *next;
}					t_stack;

void		ft_error(void);
void		is_sign(char c);
int			ft_is_duplicated(char **args);
void		ft_parsing(char **args);
void    	free_arr(char **args);
int			ft_is_intfull(char *str);
char    	**ft_parsing_stack(char **av);
void    ft_lst_add_back(t_stack **stack, t_stack *new);
int ft_size(t_stack *stack);
t_stack *ft_lst_new(int value);
t_stack	*ft_last(t_stack *stack);
t_stack	*ft_before_last(t_stack *stack);