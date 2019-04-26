/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 11:32:37 by tboissel          #+#    #+#             */
/*   Updated: 2018/11/01 12:43:53 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int		ft_stack_is_sorted(t_push_swap *check)
{
	int	i;

	if (check->size_s_a <= 1)
		return (-1);
	i = -1;
	while (++i < check->size_s_a - 1)
		if (check->stack_a[i] > check->stack_a[i + 1])
			return (0);
	return (1);
}
