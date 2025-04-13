/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urmet <urmet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:39:09 by cari              #+#    #+#             */
/*   Updated: 2025/04/13 21:44:04 by urmet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arg_check(int argc, const char **argv)
{
	if (argc == 1)
		exit(0);
	ft_null_control(argc, argv);
	ft_char_control(argc, argv);
	ft_empty_control(argc, argv);
	ft_sign_control(argc, argv);
	ft_number_control(argc, argv);
	ft_maxmin_control(argc, argv);
}
