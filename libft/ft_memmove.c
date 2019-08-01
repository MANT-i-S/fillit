/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 21:08:49 by tebatsai          #+#    #+#             */
/*   Updated: 2019/05/15 00:10:24 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dst;
	char		*source;

	dst = (char *)dest;
	source = (char *)src;
	if (src < dest && src + n > dest)
	{
		while (--n > 0)
			dst[n] = source[n];
		dst[n] = source[n];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dst[i] = source[i];
			i++;
		}
	}
	return (dest);
}
