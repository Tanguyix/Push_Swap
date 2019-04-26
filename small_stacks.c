/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 14:40:20 by tboissel          #+#    #+#             */
/*   Updated: 2018/11/08 09:01:09 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_which_small(t_push_swap *push)
{
	if (push->size_s_a == 2)
		ft_two(push);
	else if (push->size_s_a == 3)
		ft_three(push);
	else if (push->size_s_a == 4)
		ft_four(push);
	else if (push->size_s_a == 5)
		ft_five(push);
	else
		ft_small(push);
	exit(0);
}

void	ft_three(t_push_swap *p)
{
	if (ft_stack_is_sorted(p))
		return ;
	if (p->stack_a[0] > p->stack_a[1] && p->stack_a[0] < p->stack_a[2])
		ft_swap(p, 'a', 1);
	else if (p->stack_a[0] > p->stack_a[1] && p->stack_a[0] > p->stack_a[2] &&
p->stack_a[1] < p->stack_a[2])
		ft_rotate(p, 'a', 1);
	else if (p->stack_a[0] < p->stack_a[1] && p->stack_a[0] > p->stack_a[2] &&
p->stack_a[1] > p->stack_a[2])
		ft_rrotate(p, 'a', 1);
	else if (p->stack_a[0] > p->stack_a[1] && p->stack_a[0] > p->stack_a[2])
	{
		ft_rotate(p, 'a', 1);
		ft_swap(p, 'a', 1);
	}
	else
	{
		ft_rrotate(p, 'a', 1);
		ft_swap(p, 'a', 1);
	}
}

void	ft_four(t_push_swap *push)
{
	int small;
	int i;
	int size;

	i = 0;
	size = push->size_s_a;
	small = ft_get_min(push);
	while (1)
	{
		++i;
		if (push->stack_a[0] == small)
		{
			ft_push(push, 'b', 1);
			break ;
		}
		else
			ft_rotate(push, 'a', 1);
	}
	ft_three(push);
	ft_push(push, 'a', 1);
}

void	ft_five(t_push_swap *push)
{
	int	scd;
	int i;
	int cpt;
	int size;

	size = push->size_s_a;
	cpt = 0;
	i = -1;
	scd = ft_find_scd(push);
	while (++i < size && cpt < 2)
	{
		if (push->stack_a[0] <= scd && ++cpt)
			ft_push(push, 'b', 1);
		else
			ft_rotate(push, 'a', 1);
	}
	if (push->size_s_a == 3)
		ft_three(push);
	else
		ft_two(push);
	if (push->stack_b[0] < push->stack_b[1])
		ft_swap(push, 'b', 1);
	while (cpt--)
		ft_push(push, 'a', 1);
}

void	ft_small(t_push_swap *push)
{
	int	swap;

	swap = 0;
	while (push->size_s_a)
		ft_push(push, 'b', 1);
	ft_three(push);
	swap += ft_insertion(push);
	while (swap--)
		ft_rotate(push, 'a', 1);
}
