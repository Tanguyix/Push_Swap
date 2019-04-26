/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 15:47:17 by tboissel          #+#    #+#             */
/*   Updated: 2018/10/31 17:38:10 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_rrotate(t_push_swap *check, char which, char verbose)
{
	int		tmp;

	if ((which == 'a' || which == 'r') && check->size_s_a > 0)
	{
		tmp = check->stack_a[check->size_s_a - 1];
		ft_push_all(check->stack_a, check->size_s_a);
		check->stack_a[0] = tmp;
		if (verbose)
			write(1, "rra\n", 4);
	}
	else if (which == 'b' && check->size_s_b > 0)
	{
		tmp = check->stack_b[check->size_s_b - 1];
		ft_push_all(check->stack_b, check->size_s_b);
		check->stack_b[0] = tmp;
		if (verbose)
			write(1, "rrb\n", 4);
	}
	if (which == 'r')
		ft_rrotate(check, 'b', verbose);
}
