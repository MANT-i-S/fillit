/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 15:20:01 by tebatsai          #+#    #+#             */
/*   Updated: 2019/05/15 17:11:56 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	lenght(int n)
{
	size_t i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char			*s;
	size_t			len;
	unsigned int	i;

	len = lenght(n);
	i = n;
	if (n < 0)
	{
		i = -n;
		len++;
	}
	if (!(s = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	s[len] = '\0';
	s[--len] = i % 10 + '0';
	while (i /= 10)
		s[--len] = i % 10 + '0';
	if (n < 0)
		*(s + 0) = '-';
	return (s);
}
