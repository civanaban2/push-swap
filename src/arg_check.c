/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:39:09 by cari              #+#    #+#             */
/*   Updated: 2025/03/18 22:48:58 by cari             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_isnumber(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

void	ft_isint(char const *str)
{
	long long	num;

	num = ft_atoi(str);
	if (num > 2147483647 || num < -2147483648)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	ft_isunique(int argc, char const *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	arg_check(int argc, char const *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc == 1)
	{
		exit(1);
	}
	while (i < argc)
	{
		ft_isnumber(argv[i]);
		ft_isint(argv[i]);
		i++;
	}
	ft_isunique(argc, argv);
}
