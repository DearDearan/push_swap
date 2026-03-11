/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 15:15:02 by lifranco          #+#    #+#             */
/*   Updated: 2026/01/27 16:58:57 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_stack(t_stack **stack, t_stack *new)
{
	t_stack	*lastnode;

	if (!stack || !new)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	lastnode = *stack;
	while (lastnode->next)
		lastnode = lastnode->next;
	lastnode->next = new;
}

static t_stack	*new_node(int value, int index)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->value = value;
	new_node->index = index;
	new_node->next = NULL;
	return (new_node);
}

static int	index_cal(int size, long long current_val, long long *parsed)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < size)
	{
		if (parsed[i] < current_val)
			count++;
		i++;
	}
	return (count);
}

void	init_stack(t_stack **stacka, long long *parsed, int size)
{
	int		i;
	t_stack	*node;

	i = 0;
	while (i < size)
	{
		node = new_node(parsed[i], index_cal(size, parsed[i], parsed));
		add_stack(stacka, node);
		i++;
	}
}
