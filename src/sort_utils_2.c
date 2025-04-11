/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 23:17:05 by cari              #+#    #+#             */
/*   Updated: 2025/04/11 23:20:55 by cari             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_biggest_first(t_array *array)
{
	t_operation	op;

	op.a_index = array->size_a - 1;
	op.b_index = array->big_b_index;
	op.cost = -1;
	get_cost(array, &op, array->size_a - 1, array->big_b_index);
	apply_operation(array, op);
}