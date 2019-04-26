/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   med.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 10:42:38 by tboissel          #+#    #+#             */
/*   Updated: 2018/11/08 09:00:12 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int			ft_separate_stack_a(t_push_swap *push, int *sorted)
{
	int		med;
	int		i;
	int		size;

	size = push->size_s_a;
	i = -1;
	med = ft_find_quantile(sorted, push->size_s_a, 2);
	ft_separate_a(push, med);
	return (push->size_s_a);
}

void		ft_separate_a(t_push_swap *push, int med)
{
	int		i;
	int		size;
	int		last;

	last = find_last(push, med);
	size = push->size_s_a;
	i = -1;
	while (++i < size)
	{
		if (push->stack_a[0] <= med)
			ft_push(push, 'b', 1);
		else
			ft_rotate(push, 'a', 1);
		if (push->stack_b[0] == last)
			return ;
	}
}

int			find_last(t_push_swap *push, int med)
{
	int		i;

	i = push->size_s_a;
	while (--i > 0)
		if (push->stack_a[i] <= med)
			return (push->stack_a[i]);
	return (0);
}

int			ft_find_first_b(t_push_swap *push, int med)
{
	int		i;

	i = -1;
	while (++i < push->size_s_b)
	{
		if (push->stack_b[i] < med)
			return (push->stack_b[i]);
	}
	return (0);
}

int			ft_find_last_b(t_push_swap *push, int med)
{
	int		i;

	i = push->size_s_b;
	while (--i >= 0)
	{
		if (push->stack_b[i] < med)
			return (push->stack_b[i]);
	}
	return (-1);
}
