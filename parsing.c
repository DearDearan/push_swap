/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:26:03 by lifranco          #+#    #+#             */
/*   Updated: 2026/03/12 14:33:40 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

static void	freetab(char **strs)
{
	int	i;

	i = 0;
	if (!strs)
		return ;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static int	tabcount(char **argv)
{
	int		i;
	int		j;
	int		count;
	char	**tmp;

	i = 1;
	count = 0;
	if (!argv || !*argv)
		return (0);
	while (argv[i])
	{
		tmp = ft_split(argv[i], ' ');
		if (!tmp)
			return (-1);
		j = 0;
		while (tmp[j++])
			count++;
		freetab(tmp);
		i++;
	}
	return (count);
}

static int	fill_array(long long *arr, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	**tmp;

	i = 0;
	k = 0;
	while (argv[++i])
	{
		tmp = ft_split(argv[i], ' ');
		if (!tmp)
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		j = -1;
		while (tmp[++j])
			arr[k++] = ft_atol(tmp[j]);
		freetab(tmp);
	}
	return (0);
}

long long	*parse(char **args, int *size)
{
	long long	*array;
	int			error;

	error = 0;
	*size = tabcount(args);
	if (!args || !*args)
		return (NULL);
	if (*size < 0)
		return (NULL);
	array = ft_calloc(*size, sizeof(long));
	if (!array)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	error = fill_array(array, args);
	if (error < 0)
	{
		free(array);
		return (NULL);
	}
	return (array);
}
