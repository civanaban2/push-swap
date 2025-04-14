/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:12:22 by urmet             #+#    #+#             */
/*   Updated: 2025/04/15 01:21:02 by cari             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_null_control(int argc, const char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

void	ft_char_control(int argc, const char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+'
				|| argv[i][j] == ' ' || ft_isdigit(argv[i][j]))
				j++;
			else
			{
				write(2, "Error\n", 6);
				exit(1);
			}
		}
		i++;
		j = 0;
	}
}

void	ft_empty_control(int argc, const char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
				j++;
			else
				break ;
		}
		if (argv[i][j] == '\0')
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
		j = 0;
	}
}

void	ft_sign_control(int argc, const char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
			{
				if (!ft_isdigit(argv[i][j + 1]))
				{
					write(2, "Error\n", 6);
					exit(1);
				}
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	ft_number_control(int argc, const char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]))
			{
				if (argv[i][j + 1] == '-' || argv[i][j + 1] == '+')
				{
					write(2, "Error\n", 6);
					exit(1);
				}
			}
			j++;
		}
		i++;
		j = 0;
	}
}
