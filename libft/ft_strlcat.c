/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 19:02:46 by tebatsai          #+#    #+#             */
/*   Updated: 2019/05/11 00:33:05 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	t;

	i = ft_strnlen(dest, n);
	j = ft_strlen(src);
	if (i < n)
	{
		k = 0;
		t = i;
		while (t < n && k < j)
		{
			dest[t++] = src[k++];
		}
		if (t < n)
			dest[t] = '\0';
		else
			dest[n - 1] = '\0';
	}
	return (i + j);
}
