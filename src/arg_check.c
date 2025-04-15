/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 04:07:24 by cari              #+#    #+#             */
/*   Updated: 2025/04/15 04:52:31 by cari             ###   ########.fr       */
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

int	ft_zero_control(const char *str)
{
	int	i;
	int	zero;

	i = 0;
	zero = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] == '0')
			zero++;
		else
			break ;
		i++;
	}
	return (ft_strlen(str) - zero);
}
