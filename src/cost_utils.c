/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 04:07:30 by cari              #+#    #+#             */
/*   Updated: 2025/04/15 04:07:32 by cari             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_cost_forward(int a_part, int b_part, t_operation *op)
{
	int	cost;

	if (a_part >= b_part)
		cost = a_part;
	else
		cost = b_part;
	if (cost < op->cost || op->cost == -1)
	{
		op->cost = cost;
		op->ra_count = a_part;
		op->rb_count = b_part;
	}
}

void	calc_cost_backward(int a_part, int b_part, t_operation *op)
{
	int	cost;

	if (a_part >= b_part)
		cost = a_part;
	else
		cost = b_part;
	if (cost < op->cost)
	{
		op->cost = cost;
		op->ra_count = -a_part;
		op->rb_count = -b_part;
	}
}

void	calc_cost_af_bb(int a_part, int b_part, t_operation *op)
{
	int	cost;

	cost = a_part + b_part;
	if (cost < op->cost)
	{
		op->cost = cost;
		op->ra_count = a_part;
		op->rb_count = -b_part;
	}
}

void	calc_cost_ab_bf(int a_part, int b_part, t_operation *op)
{
	int	cost;

	cost = a_part + b_part;
	if (cost < op->cost)
	{
		op->cost = cost;
		op->ra_count = -a_part;
		op->rb_count = b_part;
	}
}
