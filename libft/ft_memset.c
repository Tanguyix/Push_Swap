/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:57:32 by tboissel          #+#    #+#             */
/*   Updated: 2018/11/08 08:57:32 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s_cast;
	int				i;

	i = 0;
	s_cast = (unsigned char *)s;
	while (n--)
		s_cast[i++] = (unsigned char)c;
	return (s);
}
