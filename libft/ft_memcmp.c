/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 17:04:48 by tebatsai          #+#    #+#             */
/*   Updated: 2019/05/01 19:37:15 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned const char *s;
	unsigned const char *p;
	unsigned int		i;

	i = 0;
	s = str1;
	p = str2;
	while (i < n)
	{
		if (s[i] != p[i])
			return (s[i] - p[i]);
		i++;
	}
	return (0);
}
