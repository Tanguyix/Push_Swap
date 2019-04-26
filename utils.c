/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 11:21:05 by tboissel          #+#    #+#             */
/*   Updated: 2018/11/01 11:26:08 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void		ft_error(void)
{
	ft_printf("ERROR\n");
	exit(0);
}

void		ft_ok_ko(char c)
{
	if (c == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	exit(0);
}

int			ft_check_doubles(int *stack_a, int i)
{
	int		j;

	j = -1;
	while (++j < i)
	{
		if (stack_a[j] == stack_a[i])
			return (-1);
	}
	return (0);
}

int			ft_get_min(t_push_swap *push)
{
	int		min;
	int		i;

	i = -1;
	min = 2147483647;
	while (++i < push->size_s_a)
	{
		if (push->stack_a[i] < min)
			min = push->stack_a[i];
	}
	return (min);
}

int			ft_find_scd(t_push_swap *push)
{
	int small;
	int i;
	int scd;

	scd = 2147483647;
	i = -1;
	small = ft_get_min(push);
	while (++i <= push->size_s_a)
	{
		if (push->stack_a[i] > small && push->stack_a[i] < scd)
			scd = push->stack_a[i];
	}
	return (scd);
}
