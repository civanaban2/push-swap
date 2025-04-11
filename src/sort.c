/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:30:25 by urmet             #+#    #+#             */
/*   Updated: 2025/04/11 23:58:42 by cari             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_array *array)
{
	sort_init(array);
	while (array->size_a > 3)
		push_easiest(array);
	push_back(array);
}

void	sort_init(t_array *array)
{
	if (array->size_top <= 3)
		edge_cases(array);
	else
		first_step(array);
}

void	push_easiest(t_array *array)
{
	t_operation	op;

	op = calc_easiest(array);
	apply_operation(array, op);
	write(1, "pb\n", 3);
}

void	push_back(t_array *array)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	make_biggest_first(array);
	if (array->size_a == 1)
		sort_2(array);
	else
		sort_3(array);
	while (array->size_a < array->size_top -1)
	{
		while (i < 3)
		{
			if (array->a_stack[j] > array->b_stack[1])
			{
				j++;
				write (1, "rra\n", 4);
			}
			i++;
		}
		i = j;
		write (1, "pa\n", 3);
		array->size_a++;
		array->b_stack++;
	}
	while (j++ < 3)
		write(1, "rra\n", 4);
}

void	edge_cases(t_array *array)
{
	if (array->size_top == 2)
	{
		sort_2(array);
		exit(0);
	}
	else if (array->size_top == 3)
	{
		sort_3(array);
		exit(0);
	}
}
