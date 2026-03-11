/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:24:23 by lifranco          #+#    #+#             */
/*   Updated: 2026/01/19 17:59:43 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;
	int		tmpv;
	int		tmpi;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = first->next;
	tmpv = first->value;
	tmpi = first->index;
	first->value = last->value;
	first->index = last->index;
	last->value = tmpv;
	last->index = tmpi;
}

void	push(t_stack **first, t_stack **second)
{
	t_stack	*tmp;

	if (!first || !*first)
		return ;
	tmp = *first;
	*first = (*first)->next;
	tmp->next = *second;
	*second = tmp;
}

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	rev_rotate(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}
