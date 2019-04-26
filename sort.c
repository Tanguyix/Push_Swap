/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 11:01:29 by tboissel          #+#    #+#             */
/*   Updated: 2018/11/01 16:29:34 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	init_sorted(t_push_swap *push)
{
	int	i;

	push->sorted = ft_memalloc(sizeof(int) * push->size_s_a);
	i = -1;
	while (++i < push->size_s_a)
		push->sorted[i] = push->stack_a[i];
	actual_sort(push->sorted, push->size_s_a);
}

void	ft_swap_int(int *un, int *deux)
{
	int	tmp;

	tmp = *un;
	*un = *deux;
	*deux = tmp;
}

void	actual_sort(int *tab, int size)
{
	int	i;

	i = -1;
	while (++i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			ft_swap_int(&tab[i], &tab[i + 1]);
			i = -1;
		}
	}
}

int		*init_sorted_b(t_push_swap *push)
{
	int	i;

	push->sortedb = malloc(sizeof(int) * push->size_s_b);
	i = -1;
	while (++i < push->size_s_b)
		push->sortedb[i] = push->stack_b[i];
	actual_sort(push->sortedb, push->size_s_b);
	return (NULL);
}
