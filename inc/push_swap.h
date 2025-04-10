/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urmet <urmet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:45:52 by cari              #+#    #+#             */
/*   Updated: 2025/04/11 01:53:10 by urmet            ###   ########.fr       */
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

char	**arg_check(int argc, char **argv);
t_array	get_array(char **args);
void	ft_sorted_control(t_array *array);
void	sort(t_array *array);
void	sort_init(t_array *array);
void	push_easiest(t_array *array);
void	push_back(t_array *array);
void sort_2(t_array *array);
void sort_3(t_array *array);
void first_step(t_array *array);
void	edge_cases(t_array *array);
t_operation	calc_easiest(t_array *array);
void	apply_operation(t_array *array, t_operation op);
void	print_operations(t_operation op);

#endif