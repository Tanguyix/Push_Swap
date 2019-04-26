/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 10:20:15 by tboissel          #+#    #+#             */
/*   Updated: 2018/11/01 14:21:36 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int		main(int ac, char **av)
{
	int				i;
	char			*line;
	t_push_swap		*check;

	if (ac < 2)
		exit(0);
	line = NULL;
	check = ft_memalloc(sizeof(t_push_swap));
	check->stack_a = ft_memalloc(sizeof(int) * (ac - 1));
	check->stack_b = ft_memalloc(sizeof(int) * (ac - 1));
	i = 0;
	while (++i < ac)
	{
		check->stack_a[i - 1] = ft_atoi_error(av[i]);
		if (ft_check_doubles(check->stack_a, i - 1))
			ft_error();
	}
	check->size_s_a = ac - 1;
	check->size_s_b = 0;
	while (get_next_line(0, &line) > 0 && ft_which_mv(line, check))
		free(line);
	if (ft_stack_is_sorted(check) && check->size_s_b == 0)
		ft_ok_ko(0);
	else
		ft_ok_ko(1);
}
