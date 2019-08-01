/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:22:08 by tebatsai          #+#    #+#             */
/*   Updated: 2019/05/10 18:51:12 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char			*p;
	unsigned const char		*s;

	p = s1;
	s = s2;
	while (n--)
	{
		if ((*p++ = *s++) == (unsigned char)c)
			return (unsigned char*)(p);
	}
	return (0);
}
