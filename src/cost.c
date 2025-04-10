/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urmet <urmet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 01:19:01 by urmet             #+#    #+#             */
/*   Updated: 2025/04/11 01:54:10 by urmet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_operation	calc_easiest(t_array *array)
{
	t_operation	op;
	int			a_index;
	int			b_index;

	a_index = 0;
	b_index = array->size_a;
	op.cost = -1;
	while (a_index < array->size_a)
	{
		while (b_index < array->size_top)
		{
			if (array->a_stack[a_index] < array->low_b
				|| array->a_stack[a_index] > array->big_b)
				get_cost(array, &op, a_index, array->big_b_index);
			else if (array->a_stack[a_index] < array->b_stack[b_index]
				&& array->a_stack[a_index] > array->b_stack[b_index + 1])
				get_cost(array, &op, a_index, b_index + 1);
			b_index++;
		}
		a_index++;
		b_index = array->size_a;
	}
	return (op);
}

void	get_cost(t_array *array, t_operation *op, int a_index, int b_index)
{
	
}
