/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:03:37 by tebatsai          #+#    #+#             */
/*   Updated: 2019/05/13 22:45:31 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		j;
	size_t		i;
	size_t		m;

	i = 0;
	m = -1;
	if (*s2 == '\0')
		return ((char *)s1);
	else if (*s1 == '\0')
		return (NULL);
	while (s1[++m] && i < n)
	{
		j = 0;
		i = m;
		while (s1[i] == s2[j] && i < n)
		{
			i++;
			j++;
			if (s2[j] == '\0')
				return (char *)&s1[i - j];
			else if (i == n)
				return (NULL);
		}
	}
	return (NULL);
}
