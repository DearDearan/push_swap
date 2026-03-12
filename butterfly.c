/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:08:19 by lifranco          #+#    #+#             */
/*   Updated: 2026/03/12 15:21:10 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max(t_stack **stack)
{
	int		max;
	t_stack	*tmp;

	if (!*stack)
		return (-1);
	tmp = *stack;
	max = (*stack)->index;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

static int	find_max_pos(t_stack **stack, int max)
{
	t_stack	*tmp;
	int		i;

	if (!*stack)
		return (-1);
	i = 0;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->index == max)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

static void	butterfly_chunk(t_stack **stacka, t_stack **stackb, int chunk)
{
	int	i;

	i = 0;
	while (*stacka)
	{
		if ((*stacka)->index < i)
		{
			push(stacka, stackb);
			write(1, "pb\n", 3);
			i++;
		}
		else if ((*stacka)->index < chunk + i)
		{
			push(stacka, stackb);
			rotate(stackb);
			write(1, "pb\nrb\n", 6);
			i++;
		}
		else
		{
			rotate(stacka);
			write(1, "ra\n", 3);
		}
	}
}

static void	sortb(t_stack **stacka, t_stack **stackb)
{
	int	max_index;
	int	pos;
	int	curr_size;

	while (*stackb)
	{
		curr_size = ft_stacksize(*stackb);
		max_index = find_max(stackb);
		pos = find_max_pos(stackb, max_index);
		if (pos <= (curr_size / 2) && (*stackb)->index != max_index)
		{
			rotate(stackb);
			write(1, "rb\n", 3);
		}
		else if (pos > (curr_size / 2) && (*stackb)->index != max_index)
		{
			rev_rotate(stackb);
			write(1, "rrb\n", 4);
		}
		else
		{
			push(stackb, stacka);
			write(1, "pa\n", 3);
		}
	}
}

void	butterfly(t_stack **stacka, t_stack **stackb, int size)
{
	int	chunk;

	chunk = (size / 20) + BASE_CHUNK;
	butterfly_chunk(stacka, stackb, chunk);
	sortb(stacka, stackb);
}
