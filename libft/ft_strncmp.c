/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:03:04 by tebatsai          #+#    #+#             */
/*   Updated: 2019/05/14 21:09:59 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 == *s2 && n > 0)
	{
		s1++;
		s2++;
		n--;
		if (n == 0)
			return (0);
		else if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		else if (*s1 == '\0')
			return (0);
	}
	if (n == 0)
		return (0);
	else if (*s1 != *s2)
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	else if (*s1 == '\0' || *s2 == '\0')
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	return (0);
}
