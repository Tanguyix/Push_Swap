/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainpushswap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 10:21:47 by tboissel          #+#    #+#             */
/*   Updated: 2018/11/08 09:03:42 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int				main(int ac, char **av)
{
	t_push_swap *push;
	int			rest;
	int			size;
	int			sorted;

	sorted = 0;
	rest = 0;
	push = NULL;
	push = ft_init_ps(push, ac, av);
	if (ft_stack_is_sorted(push))
		free_all(push);
	init_sorted(push);
	rest = ft_separate_stack_a(push, push->sorted);
	size = push->size_s_b;
	sorted = 0;
	while (sorted <= size)
		ft_innersort(push, size, &sorted);
	while (rest--)
		ft_push(push, 'b', 1);
	size = push->size_s_b;
	sorted = 0;
	while (sorted <= size)
		ft_innersort(push, size, &sorted);
	free_all(push);
}

void			free_all(t_push_swap *push)
{
	free(push->sorted);
	free(push->stack_a);
	free(push->stack_b);
	free(push);
	exit(0);
}

t_push_swap		*ft_init_ps(t_push_swap *push, int ac, char **av)
{
	int	i;

	i = 0;
	push = ft_memalloc(sizeof(t_push_swap));
	push->stack_a = ft_memalloc(sizeof(int) * (ac - 1));
	push->stack_b = ft_memalloc(sizeof(int) * (ac - 1));
	while (++i < ac)
	{
		push->stack_a[i - 1] = ft_atoi_error(av[i]);
		if (ft_check_doubles(push->stack_a, i - 1))
			ft_error();
	}
	push->size_s_a = ac - 1;
	if (ac - 1 <= 11 && !(ft_stack_is_sorted(push)))
		ft_which_small(push);
	push->nb_to_keep = (ac - 1) / (2.6 + ((ac - 1) / 100));
	return (push);
}

void			ft_innersort(t_push_swap *push, int size, int *sorted)
{
	int swaps;

	if (push->size_s_b > push->nb_to_keep)
		ft_push_back_in_a(push);
	swaps = ft_insertion(push);
	while (swaps--)
		ft_rotate(push, 'a', 1);
	*sorted += push->nb_to_keep;
	if (*sorted < size)
		ft_push_back_in_b(push, size - *sorted);
}

int				ft_get_max(t_push_swap *push)
{
	int	min;
	int	i;

	i = -1;
	min = 2147483647;
	while (++i < push->size_s_a)
		if (push->stack_a[i] < min)
			min = push->stack_a[i];
	return (min);
}
