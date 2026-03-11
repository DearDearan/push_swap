/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:54:14 by lifranco          #+#    #+#             */
/*   Updated: 2026/02/05 12:30:50 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_all(t_stack **stacka, t_stack **stackb, long long *tab)
{
	t_stack	*tmp;

	while (*stacka)
	{
		tmp = (*stacka)->next;
		free(*stacka);
		*stacka = tmp;
	}
	*stacka = NULL;
	while (*stackb)
	{
		tmp = (*stackb)->next;
		free(*stackb);
		*stackb = tmp;
	}
	free(tab);
	*stackb = NULL;
}

static int	only_spaces(char **argv)
{
	int		i;
	char	*error;

	i = 1;
	while (argv[i])
	{
		error = ft_strtrim(argv[i], " ");
		if (!error)
			return (1);
		if (error[0] == '\0')
		{
			free(error);
			write(2, "Error\n", 6);
			return (1);
		}
		free(error);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack		*stacka;
	t_stack		*stackb;
	int			size;
	long long	*tab;

	size = 0;
	stacka = NULL;
	stackb = NULL;
	if (argc < 2)
		return (1);
	if (check_invalid_char(argv) == 1 || check_signs(argv) == 1
		|| only_spaces(argv) == 1)
		return (1);
	tab = parse(argv, &size);
	if (check_double(tab, size) == 1 || check_overflow(tab, size))
	{
		free(tab);
		return (1);
	}
	init_stack(&stacka, tab, size);
	if (is_sorted(stacka) == 0)
		sort(&stacka, &stackb, size);
	free_all(&stacka, &stackb, tab);
	return (0);
}
