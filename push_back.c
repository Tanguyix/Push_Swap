/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:25:05 by tboissel          #+#    #+#             */
/*   Updated: 2018/11/08 09:00:52 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_push_back_in_a(t_push_swap *push)
{
	int	tenth;
	int	i;
	int size;

	if (push->size_s_b < push->nb_to_keep)
		return ;
	size = push->size_s_b;
	i = -1;
	tenth = ft_find_tenth(push);
	while (++i < size)
	{
		if (push->stack_b[0] < tenth)
			ft_rotate(push, 'b', 1);
		else
			ft_push(push, 'a', 1);
	}
}

void	ft_push_back_in_b(t_push_swap *push, int rest)
{
	while (rest--)
		ft_push(push, 'b', 1);
}

int		ft_find_tenth(t_push_swap *push)
{
	int	res;

	push->sortedb = 0;
	init_sorted_b(push);
	if (push->size_s_b <= push->nb_to_keep + 1)
		res = push->sortedb[push->size_s_b - 1] + 1;
	else
		res = push->sortedb[push->nb_to_keep];
	free(push->sortedb);
	push->sortedb = 0;
	return (res);
}

void	ft_two(t_push_swap *push)
{
	if (push->stack_a[0] > push->stack_a[1])
		ft_swap(push, 'a', 1);
}
