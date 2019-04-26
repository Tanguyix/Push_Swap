/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 15:12:21 by tboissel          #+#    #+#             */
/*   Updated: 2018/11/08 09:04:50 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_push_all(int *stack, int size)
{
	int	i;

	i = size + 1;
	while (--i >= 1)
		stack[i] = stack[i - 1];
}

void	ft_pull_all(int *stack, int size)
{
	int	i;

	i = -1;
	while (++i < size - 1)
		stack[i] = stack[i + 1];
}

int		ft_find_quantile(int *stack, int size, int quant)
{
	if (!(size % quant))
		return ((stack[size / quant] + stack[(size / quant) + 1]) / quant);
	else
		return (stack[(size / quant) + 1]);
}
