/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:59:37 by tebatsai          #+#    #+#             */
/*   Updated: 2019/05/09 20:11:42 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*c;

	c = dest;
	while (*c)
	{
		c++;
	}
	while (*src && n > 0)
	{
		*c = *src++;
		c++;
		n--;
	}
	*c = '\0';
	return (dest);
}
