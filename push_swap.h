/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:59:56 by lifranco          #+#    #+#             */
/*   Updated: 2026/03/12 15:18:23 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "include/libft/libft.h"
# include <limits.h>
# define BASE_CHUNK 8

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

/* parsing.c */
long long	*parse(char **args, int *size);
/* ft_atol.c */
long long	ft_atol(const char *str);
/* sort.c */
void		sort(t_stack **stacka, t_stack **stackb, int size);
/* init_stack */
void		init_stack(t_stack **stacka, long long *parsed, int size);
/* Error_check.c */
int			check_invalid_char(char **argv);
int			check_overflow(long long *parsed, int size);
int			check_double(long long *tab, int size);
int			check_signs(char **argv);
int			is_sorted(t_stack *stack);
/* stack_mod.c */
void		swap(t_stack **stack);
void		push(t_stack **first, t_stack **second);
void		rotate(t_stack **stack);
void		rev_rotate(t_stack **stack);
/* butterfly.c */
void		butterfly(t_stack **stacka, t_stack **stackb, int size);
/* ft_stacksize */
int			ft_stacksize(t_stack *stack);

#endif