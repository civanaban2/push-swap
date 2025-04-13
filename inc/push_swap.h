/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:45:52 by cari              #+#    #+#             */
/*   Updated: 2025/04/13 04:10:26 by cari             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_array
{
	int	*a_stack;
	int	*b_stack;
	int	size_top;
	int	size_a;
	int	big_b;
	int	low_b;
	int	big_b_index;
}	t_array;

typedef struct s_operation
{
	int	a_index;
	int	b_index;
	int	ra_count;
	int	rb_count;
	int	cost;
}	t_operation;

int			final_rra(t_array *array, int turn);
int			find_index(t_array *array, int a_index,
				int b_index, t_operation *op);
char		**arg_check(int argc, char **argv);
void		ft_sorted_control(t_array *array);
void		sort(t_array *array);
void		sort_init(t_array *array);
void		push_easiest(t_array *array);
void		push_back(t_array *array);
void		sort_2(int *a_stack);
void		sort_3(int *a_stack);
void		first_step(t_array *array);
void		edge_cases(t_array *array);
void		apply_operation(t_array *array, t_operation op);
void		print_operations(t_operation op);
void		get_cost(t_array *array, t_operation *op, int a_index, int b_index);
void		calc_cost_forward(int a_part, int b_part, t_operation *op);
void		calc_cost_backward(int a_part, int b_part, t_operation *op);
void		calc_cost_af_bb(int a_part, int b_part, t_operation *op);
void		calc_cost_ab_bf(int a_part, int b_part, t_operation *op);
void		print_forward_op(int ra_count, int rb_count);
void		print_backward_op(int ra_count, int rb_count);
void		print_af_bb_op(int ra_count, int rb_count);
void		print_ab_bf_op(int ra_count, int rb_count);
void		get_new_values(t_array *array, t_operation op);
void		make_biggest_first(t_array *array);
void		merge(t_array *array);
t_array		get_array(char **args);
t_operation	calc_easiest(t_array *array);

#endif