/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:12:57 by tebatsai          #+#    #+#             */
/*   Updated: 2019/05/14 22:27:05 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	size_t	i;
	char	*p;
	char	*s;

	p = (char *)str1;
	s = (char *)str2;
	i = 0;
	while (i < n)
	{
		p[i] = s[i];
		i++;
	}
	str1 = (void *)p;
	return (str1);
}
