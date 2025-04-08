/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urmet <urmet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:45:52 by cari              #+#    #+#             */
/*   Updated: 2025/04/06 20:39:54 by urmet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_array
{
	int *numbers;
	int size_top;
	int size_a;
	int size_b;
	int big_b;
	int low_b;
	int big_b_index;
	int low_b_index;
}	t_array;

typedef struct s_operation
{
	int a_index;
	int b_index;
	int ra_count;
	int rb_count;
	int cost;
} t_operation;

char	**arg_check(int argc, char **argv);
t_array get_array(char **args);
void	ft_sorted_control(t_array *array);
void	sort(t_array *array);
void	final_sort(t_array *array);
void	push_easiest(t_array *array);
t_operation	get_easiest(t_array *array);
void	sort_init(t_array *array);
void	calc_cost(t_operation *op, int a_index, int b_index, t_array *array);
void	apply_operation(t_operation op, t_array *array);

#endif