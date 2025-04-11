/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:31:10 by urmet             #+#    #+#             */
/*   Updated: 2025/04/12 00:23:16 by cari             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_array *array)
{
	int	tmp;

	if (array->a_stack[0] > array->a_stack[1])
		write(1, "sa\n", 3);
	tmp = array->a_stack[array->size_a - 1];
	array->a_stack[array->size_a - 1] = array->a_stack[array->size_a - 2];
	array->a_stack[array->size_a - 2] = tmp;
}

void	sort_3(t_array *array)
{
	int a = array->a_stack[0];
	int b = array->a_stack[1];
	int c = array->a_stack[2];
	int tmp;

	// a < b < c → c > b > a (tam tersi) için:
	if (a < b && b < c)
	{
		write(1, "sa\n", 3);
		write(1, "rra\n", 4);
		tmp = array->a_stack[0];
		array->a_stack[0] = array->a_stack[2];
		array->a_stack[2] = tmp;
	}
	// b < a < c → c > a > b
	else if (b < a && a < c)
	{
		write(1, "ra\n", 3);
		tmp = array->a_stack[0];
		array->a_stack[0] = array->a_stack[2];
		array->a_stack[2] = array->a_stack[1];
		array->a_stack[1] = tmp;
	}
	// a < c < b → b > c > a
	else if (a < c && c < b)
	{
		write(1, "rra\n", 4);
		tmp = array->a_stack[0];
		array->a_stack[0] = array->a_stack[1];
		array->a_stack[1] = array->a_stack[2];
		array->a_stack[2] = tmp;
	}
	// b < c < a → a > c > b
	else if (b < c && c < a)
	{
		write(1, "sa\n", 3);
		tmp = array->a_stack[1];
		array->a_stack[1] = array->a_stack[2];
		array->a_stack[2] = tmp;
	}
	// c < a < b → b > a > c
	else if (c < a && a < b)
	{
		write(1, "sa\n", 3);
		write(1, "ra\n", 3);
		tmp = array->a_stack[0];
		array->a_stack[0] = array->a_stack[1];;
		array->a_stack[1] = tmp;
	}
	// Diğer durumda zaten sıralı: a > b > c
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
	ft_memcpy(array->b_stack + part_long, tmp, 4 * (op.b_index - array->size_a));
	free(tmp);
	get_new_values(array, op);
	print_operations(op);
}

void	get_new_values(t_array *array, t_operation op)
{
	array->size_a--;
	array->b_stack--;
	if (array->a_stack[array->size_a] > array->big_b)
	{
		array->big_b = array->a_stack[array->size_a];
		array->big_b_index = array->size_a;
	}
	else if (array->a_stack[array->size_a] < array->low_b)
		array->low_b = array->a_stack[array->size_a];
	else
	{
		array->big_b_index -= op.b_index - array->size_a;
		if (array->big_b_index < array->size_a)
			array->big_b_index += array->size_top - array->size_a; 
	}
}