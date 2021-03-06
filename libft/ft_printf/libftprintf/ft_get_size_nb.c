/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size_nb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 02:12:48 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/01 02:18:45 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_get_size_nb(intmax_t nb)
{
	int		i;

	if (nb == 0)
		return (1);
	i = ((nb < 0) ? 1 : 0);
	while (nb != 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}
