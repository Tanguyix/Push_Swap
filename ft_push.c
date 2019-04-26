/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 13:29:00 by tboissel          #+#    #+#             */
/*   Updated: 2018/10/31 17:25:10 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_push(t_push_swap *check, char which, char verbose)
{
	if (which == 'a' && check->size_s_b > 0)
	{
		ft_push_all(check->stack_a, check->size_s_a);
		check->stack_a[0] = check->stack_b[0];
		ft_pull_all(check->stack_b, check->size_s_b);
		check->size_s_a++;
		check->size_s_b--;
		if (verbose)
			write(1, "pa\n", 3);
	}
	else if (which == 'b' && check->size_s_a > 0)
	{
		ft_push_all(check->stack_b, check->size_s_b);
		check->stack_b[0] = check->stack_a[0];
		ft_pull_all(check->stack_a, check->size_s_a);
		check->size_s_b++;
		check->size_s_a--;
		if (verbose)
			write(1, "pb\n", 3);
	}
}
