/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:05:32 by lifranco          #+#    #+#             */
/*   Updated: 2026/03/12 11:55:44 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort3num(t_stack **stacka)
{
	int	top;
	int	mid;
	int	bot;

	top = (*stacka)->index;
	mid = (*stacka)->next->index;
	bot = (*stacka)->next->next->index;
	if (top > mid && top > bot)
	{
		rotate(stacka);
		write(1, "ra\n", 3);
	}
	else if (mid > top && mid > bot)
	{
		rev_rotate(stacka);
		write(1, "rra\n", 4);
	}
	top = (*stacka)->index;
	mid = (*stacka)->next->index;
	bot = (*stacka)->next->next->index;
	if (top > mid)
	{
		swap(stacka);
		write(1, "sa\n", 3);
	}
}

static void	sortpos(t_stack **stacka, t_stack **stackb, int *i)
{
	if ((*stacka)->index == 0 || (*stacka)->index == 1)
	{
		push(stacka, stackb);
		write(1, "pb\n", 3);
		(*i)++;
	}
	else
	{
		rotate(stacka);
		write(1, "ra\n", 3);
	}
}

static void	sort5num(t_stack **stacka, t_stack **stackb)
{
	int	i;

	i = 0;
	while (i < 2)
		sortpos(stacka, stackb, &i);
	sort3num(stacka);
	if ((*stackb)->index < (*stackb)->next->index)
	{
		swap(stackb);
		write(1, "sb\n", 3);
	}
	push(stackb, stacka);
	push(stackb, stacka);
	write(1, "pa\n", 3);
	write(1, "pa\n", 3);
}

static void	sort4num(t_stack **stacka, t_stack **stackb)
{
	while ((*stacka)->index != 0)
	{
		rotate(stacka);
		write(1, "ra\n", 3);
	}
	push(stacka, stackb);
	write(1, "pb\n", 3);
	sort3num(stacka);
	push(stackb, stacka);
	write(1, "pa\n", 3);
}

void	sort(t_stack **stacka, t_stack **stackb, int size)
{
	if (is_sorted(*stacka) == 1)
		return ;
	else if (size == 2)
	{
		swap(stacka);
		write(1, "sa\n", 3);
		return ;
	}
	else if (size == 3)
		sort3num(stacka);
	else if (size == 4)
		sort4num(stacka, stackb);
	else if (size == 5)
		sort5num(stacka, stackb);
	else
		butterfly(stacka, stackb, size);
}
