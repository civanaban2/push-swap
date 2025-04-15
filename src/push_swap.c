/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 04:07:52 by cari              #+#    #+#             */
/*   Updated: 2025/04/15 04:07:54 by cari             ###   ########.fr       */
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
