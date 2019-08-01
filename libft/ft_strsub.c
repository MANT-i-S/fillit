/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 22:16:53 by tebatsai          #+#    #+#             */
/*   Updated: 2019/05/13 23:34:46 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*c;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(c = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (len == 0)
		return (c);
	while (i < len)
	{
		c[i] = s[start];
		start++;
		i++;
	}
	c[i] = '\0';
	return (c);
}
