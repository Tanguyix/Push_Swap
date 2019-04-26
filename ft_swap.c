/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 12:33:48 by tboissel          #+#    #+#             */
/*   Updated: 2018/10/31 17:26:52 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_swap(t_push_swap *check, char which, char verbose)
{
	int	tmp;

	if (which == 'a' || which == 's')
	{
		if (check->size_s_a <= 1)
			return ;
		tmp = check->stack_a[0];
		check->stack_a[0] = check->stack_a[1];
		check->stack_a[1] = tmp;
		if (verbose)
			write(1, "sa\n", 3);
	}
	else if (which == 'b')
	{
		if (check->size_s_b <= 1)
			return ;
		tmp = check->stack_b[0];
		check->stack_b[0] = check->stack_b[1];
		check->stack_b[1] = tmp;
		if (verbose)
			write(1, "sb\n", 3);
	}
	if (which == 's')
		ft_swap(check, 'b', verbose);
}
