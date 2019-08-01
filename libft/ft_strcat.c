/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 10:40:23 by tebatsai          #+#    #+#             */
/*   Updated: 2019/05/09 19:21:40 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char *c;

	c = dest;
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src++;
		dest++;
	}
	*dest = '\0';
	return (c);
}
