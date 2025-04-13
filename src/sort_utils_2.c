/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urmet <urmet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 23:17:05 by cari              #+#    #+#             */
/*   Updated: 2025/04/13 21:56:38 by urmet            ###   ########.fr       */
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

void	merge(t_array *array)
{
	int	rra_count;
	int	turn;

	turn = array->size_a;
	while (array->size_a < array->size_top)
	{
		rra_count = final_rra(array, turn);
		write(1, "pa\n", 3);
		array->size_a++;
	}
	while (rra_count++ < turn)
		write(1, "rra\n", 4);
}

int	final_rra(t_array *array, int turn)
{
	static int	i;
	int			rra_count;
	static int	flag;

	if (flag <= 1)
		flag++;
	rra_count = 0;
	if (i == turn)
		return (i);
	while (i < turn)
	{
		if (array->a_stack[i] > array->a_stack[array->size_a])
		{
			rra_count++;
			i++;
		}
		else
			break ;
	}
	if (rra_count != turn || flag != 1)
	{
		while (rra_count--)
			write(1, "rra\n", 4);
	}
	return (i);
}
