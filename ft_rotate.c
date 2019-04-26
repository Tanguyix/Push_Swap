/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 15:13:47 by tboissel          #+#    #+#             */
/*   Updated: 2018/10/31 17:25:54 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_rotate(t_push_swap *check, char which, char verbose)
{
	int		tmp;

	if ((which == 'a' || which == 'r') && check->size_s_a > 0)
	{
		tmp = check->stack_a[0];
		ft_pull_all(check->stack_a, check->size_s_a);
		check->stack_a[check->size_s_a - 1] = tmp;
		if (verbose)
			write(1, "ra\n", 3);
	}
	else if (which == 'b' && check->size_s_b > 0)
	{
		tmp = check->stack_b[0];
		ft_pull_all(check->stack_b, check->size_s_b);
		check->stack_b[check->size_s_b - 1] = tmp;
		if (verbose)
			write(1, "rb\n", 3);
	}
	if (which == 'r')
		ft_rotate(check, 'b', verbose);
}
