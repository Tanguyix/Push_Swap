/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 10:55:56 by tboissel          #+#    #+#             */
/*   Updated: 2018/11/05 12:26:02 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "../libft/ft_printf/libftprintf/libftprintf.h"

typedef	struct	s_push_swap
{
	int			size_s_a;
	int			size_s_b;
	int			*stack_a;
	int			*stack_b;
	int			*sorted;
	int			nb_to_keep;
	int			med;
	int			*sortedb;
}				t_push_swap;

int				ft_check_doubles(int *stack_a, int i);
void			ft_error(void);
void			ft_ok_ko(char c);
int				ft_stack_is_sorted(t_push_swap *check);
int				ft_which_mv(char *line, t_push_swap *check);
double			ft_atoi_error(const char *nptr);

t_push_swap		*ft_init_ps(t_push_swap *push, int ac, char **av);
void			ft_swap(t_push_swap *check, char which, char verbose);
void			ft_push(t_push_swap *check, char which, char verbose);
void			ft_rotate(t_push_swap *check, char which, char verbose);
void			ft_rrotate(t_push_swap *check, char which, char verbose);
void			ft_push_all(int *stack, int size);
void			ft_pull_all(int *stack, int size);
void			free_all(t_push_swap *push);

void			init_sorted(t_push_swap *swap);
int				ft_find_quantile(int *stack, int size, int quant);
void			actual_sort(int *tab, int size);
int				ft_insertion(t_push_swap *push);
int				ft_find_minimum(t_push_swap *push);
int				ft_find_maximum(t_push_swap *push);
int				ft_find_first_b(t_push_swap *push, int med);
int				ft_find_last_b(t_push_swap *push, int med);
void			ft_separate_a(t_push_swap *push, int med);
int				ft_separate_stack_a(t_push_swap *push, int *sorted);
int				*init_sorted_b(t_push_swap *push);
int				ft_find_tenth(t_push_swap *push);
void			ft_push_back_in_b(t_push_swap *push, int rest);
void			ft_push_back_in_a(t_push_swap *push);
void			ft_insert_max(t_push_swap *push, int pos);
void			ft_insert_min(t_push_swap *push, int pos_max, int *swaps);
void			ft_innersort(t_push_swap *p, int size, int *sorted);

void			ft_which_small(t_push_swap *push);
void			ft_two(t_push_swap *push);
void			ft_three(t_push_swap *push);
void			ft_five(t_push_swap *push);
int				ft_get_min(t_push_swap *push);
int				ft_find_scd(t_push_swap *push);
void			ft_four(t_push_swap *push);
void			ft_small(t_push_swap *push);
int				find_last(t_push_swap *push, int med);

#endif
