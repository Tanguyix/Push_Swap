/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 17:06:42 by tboissel          #+#    #+#             */
/*   Updated: 2018/11/08 09:07:15 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

double	ft_atoi_error(const char *nptr)
{
	double	neg_test;
	double	result;

	neg_test = 1;
	result = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg_test = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
		result = result * 10 + *nptr++ - '0';
	if (*nptr && !(ft_isdigit(*nptr)))
		ft_error();
	if (*(nptr - 1) && *(nptr - 1) != '0' && result == 0)
		ft_error();
	if (result * neg_test > 2147483647 || result * neg_test < -2147483648)
		ft_error();
	return (result * neg_test);
}
