/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 12:19:33 by tebatsai          #+#    #+#             */
/*   Updated: 2019/05/11 17:51:26 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int			i;
	int			j;
	const char	*c;

	c = s2;
	i = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	else if (*s1 == '\0')
		return (NULL);
	while (s1[i])
	{
		j = 0;
		while (s1[i + j] == s2[j])
		{
			j++;
			if (s2[j] == '\0')
				return ((char*)&s1[i]);
		}
		i++;
	}
	return (NULL);
}
