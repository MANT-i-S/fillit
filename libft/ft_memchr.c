/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 23:57:47 by tebatsai          #+#    #+#             */
/*   Updated: 2019/05/09 18:13:19 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*b;
	size_t				i;

	i = 0;
	b = str;
	while (i < n)
	{
		if (b[i] == (unsigned char)c)
			return (unsigned char*)&b[i];
		i++;
	}
	return (0);
}
