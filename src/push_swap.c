/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urmet <urmet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:39:11 by cari              #+#    #+#             */
/*   Updated: 2025/04/05 20:57:20 by urmet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char const *argv[])
{
	char **args;
	t_array	array;
	args = arg_check(argc, (char **) argv);
	array = get_array(args);
	ft_sorted_control(&array);
	while (1)
		sort(&array);
	return (0);
}
