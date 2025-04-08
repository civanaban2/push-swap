/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urmet <urmet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:39:09 by cari              #+#    #+#             */
/*   Updated: 2025/04/05 20:57:48 by urmet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] == '-')
		{
			i++;
			continue ;
		}
		if (str[i] < '0' || str[i] > '9')
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

void	ft_isint(char *str)
{
	long long	num;

	num = ft_atol(str);
	if (ft_strlen(str) > 11)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (num > 2147483647 || num < -2147483648)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	ft_isunique(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i -1]) == ft_atoi(argv[j -1]))
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

char	**arg_check(int argc, char **argv)
{
	int		i;
	int		j;
	char	**args;

	i = 1;
	j = 0;
	if (argc == 1)
		exit(1);
	else if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		while (args[j])
			j++;
		argc = j + 1;
	}
	else
		args = &argv[1];
	while (i < argc)
	{
		ft_isnumber(args[i - 1]);
		ft_isint(args[i - 1]);
		i++;
	}
	ft_isunique(argc, args);
	return (args);
}

void	ft_sorted_control(t_array *array)
{
	int	i;

	i = 0;
	while (i < array->size_top - 1)
	{
		if (array->numbers[i] < array->numbers[i + 1])
			return ;
		i++;
	}
	free(array->numbers);
	exit(0);
}
