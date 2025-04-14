/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:20:54 by urmet             #+#    #+#             */
/*   Updated: 2025/04/15 01:23:07 by cari             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_maxmin_control(int argc, const char **argv)
{
	int		i;
	int		j;
	long	num;
	char	**numbers;

	i = 1;
	j = 0;
	while (i < argc)
	{
		numbers = ft_split(argv[i], ' ');
		while (numbers[j])
		{
			num = ft_atol(numbers[j]);
			if (num > 2147483647 || num < -2147483648
				|| ft_strlen(numbers[j]) > 11)
			{
				write(2, "Error\n", 6);
				free_split(numbers);
				exit(1);
			}
			j++;
		}
		free_split(numbers);
		i++;
		j = 0;
	}
}

void	get_array(t_array *array, int argc, const char **argv)
{
	int		i;
	int		j;
	char	**numbers;

	array->size_a = 0;
	array->size_top = count_numbers(argc, argv);
	array->a_stack = malloc(sizeof(int) * array->size_top);
	j = 0;
	i = 1;
	while (i < argc)
	{
		numbers = ft_split(argv[i], ' ');
		while (numbers[j])
		{
			array->a_stack[array->size_top - array->size_a - 1]
				= ft_atoi(numbers[j]);
			j++;
			array->size_a++;
		}
		free_split(numbers);
		i++;
		j = 0;
	}
	ft_unique_control(array);
	ft_sorted_control(array);
}

int	count_numbers(int argc, const char **argv)
{
	int		i;
	int		j;
	int		count;
	char	**numbers;

	i = 1;
	j = 0;
	count = 0;
	while (i < argc)
	{
		numbers = ft_split(argv[i], ' ');
		while (numbers[j])
		{
			count++;
			j++;
		}
		free_split(numbers);
		i++;
		j = 0;
	}
	return (count);
}

void	ft_sorted_control(t_array *array)
{
	int	i;

	i = 0;
	while (i < array->size_top - 1)
	{
		if (array->a_stack[i] < array->a_stack[i + 1])
			return ;
		i++;
	}
	free(array->a_stack);
	exit(0);
}

void	ft_unique_control(t_array *array)
{
	int	i;
	int	j;

	i = 0;
	while (i < array->size_top)
	{
		j = i + 1;
		while (j < array->size_top)
		{
			if (array->a_stack[i] == array->a_stack[j])
			{
				write(2, "Error\n", 6);
				free(array->a_stack);
				exit(1);
			}
			j++;
		}
		i++;
	}
}
