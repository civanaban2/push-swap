/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 20:00:13 by cari              #+#    #+#             */
/*   Updated: 2025/04/11 23:18:26 by cari             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_operations(t_operation op)
{
	if (op.ra_count >= 0 && op.rb_count >= 0)
		print_forward_op(op.ra_count, op.rb_count);
	else if (op.ra_count < 0 && op.rb_count < 0)
		print_backward_op(op.ra_count, op.rb_count);
	else if (op.ra_count >= 0 && op.rb_count < 0)
		print_af_bb_op(op.ra_count, op.rb_count);
	else if (op.ra_count < 0 && op.rb_count >= 0)
		print_ab_bf_op(op.ra_count, op.rb_count);
}

void	print_forward_op(int ra_count, int rb_count)
{
	if (ra_count >= rb_count)
	{
		while (rb_count-- > 0)
		{
			write(1, "rr\n", 3);
			ra_count--;
		}
		while (ra_count-- > 0)
			write(1, "ra\n", 3);
	}
	else
	{
		while (ra_count-- > 0)
		{
			write(1, "rr\n", 3);
			rb_count--;
		}
		while (rb_count-- > 0)
			write(1, "rb\n", 3);
	}
}

void	print_backward_op(int ra_count, int rb_count)
{
	if (ra_count <= rb_count)
	{
		while (rb_count++ < 0)
		{
			write(1, "rrr\n", 4);
			ra_count++;
		}
		while (ra_count++ < 0)
			write(1, "rra\n", 4);
	}
	else
	{
		while (ra_count++ < 0)
		{
			write(1, "rrr\n", 4);
			rb_count++;
		}
		while (rb_count++ < 0)
			write(1, "rrb\n", 4);
	}
}

void	print_af_bb_op(int ra_count, int rb_count)
{
	while (ra_count-- > 0)
		write(1, "ra\n", 3);
	while (rb_count++ < 0)
		write(1, "rrb\n", 4);
}

void	print_ab_bf_op(int ra_count, int rb_count)
{
	while (ra_count++ < 0)
		write(1, "rra\n", 4);
	while (rb_count-- > 0)
		write(1, "rb\n", 3);
}
