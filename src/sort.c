/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:30:25 by urmet             #+#    #+#             */
/*   Updated: 2025/04/13 02:19:12 by cari             ###   ########.fr       */
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
	make_biggest_first(array);
	array->size_a++;
	array->b_stack++;
	if (array->size_a == 2)
		sort_2(array->a_stack);
	else
		sort_3(array->a_stack);
	merge(array);
}

void	edge_cases(t_array *array)
{
	if (array->size_top == 2)
	{
		sort_2(array->a_stack);
		free(array->a_stack);
		exit(0);
	}
	else if (array->size_top == 3)
	{
		sort_3(array->a_stack);
		free(array->a_stack);
		exit(0);
	}
}
