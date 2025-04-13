/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urmet <urmet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:39:11 by cari              #+#    #+#             */
/*   Updated: 2025/04/13 21:29:24 by urmet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char const *argv[])
{
	t_array	array;

	arg_check(argc, argv);
	get_array(&array, argc, argv);
	sort(&array);
	free(array.a_stack);
	return (0);
}
