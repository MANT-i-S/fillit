/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 20:58:13 by tebatsai          #+#    #+#             */
/*   Updated: 2019/05/15 16:58:54 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	back(const char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	i--;
	while (ft_isitspace(s[i]))
		i--;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	int		g;
	char	*c;

	i = 0;
	g = 0;
	if (!s)
		return (NULL);
	len = back(s);
	while (ft_isitspace(s[i]))
	{
		i++;
		if (s[i] == '\0')
			len = i;
	}
	if (!s || !(c = (char*)malloc(sizeof(char) * (len + 2) - i)))
		return (NULL);
	while (i <= len)
		c[g++] = s[i++];
	c[g] = '\0';
	return (c);
}
