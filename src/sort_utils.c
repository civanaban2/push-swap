/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urmet <urmet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:31:10 by urmet             #+#    #+#             */
/*   Updated: 2025/04/11 01:53:01 by urmet            ###   ########.fr       */
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
}

void	first_step(t_array *array)
{
	array->b_stack = array->a_stack + array->size_top - 2;
	array->size_a -= 2;
	if (array->a_stack + array->size_top > array->a_stack + array->size_top - 1)
	{
		array->big_b = array->a_stack[array->size_top - 1];
		array->low_b = array->a_stack[array->size_top - 2];
		array->big_b_index = array->size_top - 1;
	}
	else
	{
		array->big_b = array->a_stack[array->size_top - 2];
		array->low_b = array->a_stack[array->size_top - 1];
		array->big_b_index = array->size_top - 2;
	}
	write(1, "pb\npb\n", 6);
}

void	apply_operation(t_array *array, t_operation op)
{
	char *tmp;
	int part_long;

	part_long = array->size_a - op.a_index;
	tmp = malloc(sizeof(int) * (op.a_index + 1));
	ft_memcpy(tmp, array->a_stack, sizeof(int) * (op.a_index + 1));
	ft_memcpy(array->a_stack, array->a_stack + op.a_index, sizeof(int) * part_long);
	ft_memcpy(array->a_stack + part_long, tmp, sizeof(int) * (op.a_index + 1));
	free(tmp);
	part_long = array->size_top - op.b_index;
	tmp = malloc(sizeof(int) * (op.b_index - array->size_a + 1));
	ft_memcpy(tmp, array->b_stack, sizeof(int) * (op.b_index - array->size_a + 1));
	ft_memcpy(array->b_stack, array->a_stack + op.b_index, sizeof(int) * part_long);
	ft_memcpy(array->b_stack + part_long, tmp, sizeof(int) * (op.b_index - array->size_a + 1));
	free(tmp);
	print_operations(op);
}

void	print_operations(t_operation op)
{
	
}
