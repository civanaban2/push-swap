/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:31:10 by urmet             #+#    #+#             */
/*   Updated: 2025/04/13 02:47:19 by cari             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(int *a_stack)
{
	int	tmp;

	if (a_stack[0] < a_stack[1])
	{
		write(1, "sa\n", 3);
		tmp = a_stack[0];
		a_stack[0] = a_stack[1];
		a_stack[1] = tmp;
	}
}

void	sort_3(int *a_stack)
{
	int	tmp;

	sort_2(a_stack + 1);
	if (a_stack[0] < a_stack[2])
	{
		write(1, "rra\n", 4);
		tmp = a_stack[0];
		a_stack[0] = a_stack[1];
		a_stack[1] = a_stack[2];
		a_stack[2] = tmp;
	}
	else if (a_stack[0] < a_stack[1])
	{
		write(1, "rra\n", 4);
		tmp = a_stack[0];
		a_stack[0] = a_stack[1];
		a_stack[1] = a_stack[2];
		a_stack[2] = tmp;
		sort_2(a_stack +1);
	}
}

void	first_step(t_array *array)
{
	array->size_a -= 2;
	array->b_stack = array->a_stack + array->size_a;
	if (array->a_stack[array->size_a] > array->a_stack[array->size_a + 1])
	{
		array->big_b = array->a_stack[array->size_a];
		array->low_b = array->a_stack[array->size_a + 1];
		array->big_b_index = array->size_a;
	}
	else
	{
		array->big_b = array->a_stack[array->size_a +1];
		array->low_b = array->a_stack[array->size_a];
		array->big_b_index = array->size_a + 1;
	}
	write(1, "pb\npb\n", 6);
}

void	apply_operation(t_array *array, t_operation op)
{
	int	*tmp;
	int	part_long;

	part_long = array->size_a - op.a_index - 1;
	tmp = malloc(4 * (op.a_index + 1));
	ft_memcpy(tmp, array->a_stack, 4 * (op.a_index + 1));
	ft_memcpy(array->a_stack, array->a_stack + op.a_index + 1, 4 * part_long);
	ft_memcpy(array->a_stack + part_long, tmp, 4 * (op.a_index + 1));
	free(tmp);
	part_long = array->size_top - op.b_index;
	tmp = malloc(4 * (op.b_index - array->size_a));
	ft_memcpy(tmp, array->b_stack, 4 * (op.b_index - array->size_a));
	ft_memcpy(array->b_stack, array->a_stack + op.b_index, 4 * part_long);
	ft_memcpy(array->b_stack + part_long, tmp, 4 *(op.b_index - array->size_a));
	free(tmp);
	get_new_values(array, op);
	print_operations(op);
}

void	get_new_values(t_array *array, t_operation op)
{
	if (array->a_stack[array->size_a -1] > array->big_b)
	{
		array->big_b = array->a_stack[array->size_a -1];
		array->big_b_index = array->size_a -1;
	}
	else if (array->a_stack[array->size_a -1] < array->low_b)
	{
		array->low_b = array->a_stack[array->size_a -1];
		array->big_b_index -= op.rb_count;
		if (array->big_b_index < array->size_a)
			array->big_b_index += array->size_top - array->size_a;
		else if (array->big_b_index > array->size_top - 1)
			array->big_b_index -= array->size_top - array->size_a;
	}
	else
	{
		array->big_b_index -= op.rb_count;
		if (array->big_b_index < array->size_a)
			array->big_b_index += array->size_top - array->size_a;
		else if (array->big_b_index > array->size_top - 1)
			array->big_b_index -= array->size_top - array->size_a;
	}
	array->size_a--;
	array->b_stack--;
}
