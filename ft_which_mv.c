/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_mv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 11:58:58 by tboissel          #+#    #+#             */
/*   Updated: 2018/11/01 14:19:57 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int		ft_which_mv(char *line, t_push_swap *check)
{
	if (!ft_strcmp(line, "sa"))
		ft_swap(check, 'a', 0);
	else if (!ft_strcmp(line, "sb"))
		ft_swap(check, 'b', 0);
	else if (!ft_strcmp(line, "ss"))
		ft_swap(check, 's', 0);
	else if (!ft_strcmp(line, "pa"))
		ft_push(check, 'a', 0);
	else if (!ft_strcmp(line, "pb"))
		ft_push(check, 'b', 0);
	else if (!ft_strcmp(line, "ra"))
		ft_rotate(check, 'a', 0);
	else if (!ft_strcmp(line, "rb"))
		ft_rotate(check, 'b', 0);
	else if (!ft_strcmp(line, "rr"))
		ft_rotate(check, 'r', 0);
	else if (!ft_strcmp(line, "rra"))
		ft_rrotate(check, 'a', 0);
	else if (!ft_strcmp(line, "rrb"))
		ft_rrotate(check, 'b', 0);
	else if (!ft_strcmp(line, "rrr"))
		ft_rrotate(check, 'r', 0);
	else
		ft_error();
	return (1);
}
