/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 01:19:01 by urmet             #+#    #+#             */
/*   Updated: 2025/04/12 00:45:57 by cari             ###   ########.fr       */
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
			{
				get_cost(array, &op, a_index, array->big_b_index);
				break;
			}
			else if (array->a_stack[a_index] < array->a_stack[b_index]
				&& array->a_stack[a_index] > array->a_stack[b_index + 1])
			{
				if (b_index +1 == array->size_top)
					get_cost(array, &op, a_index, array->size_a);
				else
					get_cost(array, &op, a_index, b_index + 1);
			}
			b_index++;
		}
		a_index++;
		b_index = array->size_a;
	}
	return (op);
}

void	get_cost(t_array *array, t_operation *op, int a_index, int b_index)
{
	int	a_forward;
	int	a_backward;
	int	b_forward;
	int	b_backward;
	int	cost_first;

	a_forward = array->size_a - a_index -1;
	a_backward = a_index + 1;
	b_forward = b_index - array->size_a;
	b_backward = array->size_top - b_index;
	cost_first = op->cost;
	calc_cost_forward(a_forward, b_forward, op);
	calc_cost_backward(a_backward, b_backward, op);
	calc_cost_af_bb(a_forward, b_backward, op);
	calc_cost_ab_bf(a_backward, b_forward, op);
	if (op->cost < cost_first || cost_first == -1)
	{
		op->a_index = a_index;
		op->b_index = b_index;
	}
}
