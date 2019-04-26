/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 14:37:07 by tboissel          #+#    #+#             */
/*   Updated: 2018/11/05 12:26:36 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int			ft_insertion(t_push_swap *push)
{
	int	pos;
	int	pos_max;
	int	swaps;
	int	sorted;

	sorted = push->size_s_b;
	swaps = 0;
	while (push->size_s_b)
	{
		pos_max = ft_find_maximum(push);
		pos = ft_find_minimum(push);
		if (ft_abs(pos_max - (push->size_s_b / 2)) <
ft_abs(pos - (push->size_s_b / 2)))
			ft_insert_max(push, pos);
		else
			ft_insert_min(push, pos_max, &swaps);
	}
	return (swaps);
}

void		ft_insert_max(t_push_swap *push, int pos)
{
	int	min_max;

	min_max = push->stack_b[pos];
	if (pos < (push->size_s_b / 2))
	{
		while (push->stack_b[0] != min_max)
			ft_rotate(push, 'b', 1);
		ft_push(push, 'a', 1);
		pos = ft_find_minimum(push);
		min_max = push->stack_b[pos];
		ft_rotate(push, 'a', 1);
	}
	else
	{
		while (push->stack_b[0] != min_max)
			ft_rrotate(push, 'b', 1);
		if (push->size_s_b)
		{
			ft_push(push, 'a', 1);
			pos = ft_find_minimum(push);
			min_max = push->stack_b[pos];
			ft_rotate(push, 'a', 1);
		}
	}
}

void		ft_insert_min(t_push_swap *push, int pos_max, int *swaps)
{
	int	min_max;

	min_max = push->stack_b[pos_max];
	if (pos_max < (push->size_s_b / 2))
	{
		while (push->stack_b[0] != min_max)
			ft_rotate(push, 'b', 1);
		ft_push(push, 'a', 1);
		pos_max = ft_find_maximum(push);
		min_max = push->stack_b[pos_max];
		*swaps += 1;
	}
	else
	{
		while (push->stack_b[0] != min_max)
			ft_rrotate(push, 'b', 1);
		if (push->size_s_b)
		{
			ft_push(push, 'a', 1);
			pos_max = ft_find_maximum(push);
			min_max = push->stack_b[pos_max];
			*swaps += 1;
		}
	}
}

int			ft_find_minimum(t_push_swap *push)
{
	int	min;
	int	i;
	int pos;

	pos = 0;
	min = push->stack_b[0];
	i = 0;
	while (++i < push->size_s_b)
		if (push->stack_b[i] < min)
		{
			min = push->stack_b[i];
			pos = i;
		}
	return (pos);
}

int			ft_find_maximum(t_push_swap *push)
{
	int	max;
	int	i;
	int pos_max;

	pos_max = 0;
	max = push->stack_b[0];
	i = 0;
	while (++i < push->size_s_b)
		if (push->stack_b[i] > max)
		{
			max = push->stack_b[i];
			pos_max = i;
		}
	return (pos_max);
}
