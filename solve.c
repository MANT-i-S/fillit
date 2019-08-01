/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:54:27 by tebatsai          #+#    #+#             */
/*   Updated: 2019/07/03 16:21:46 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			back(char *lol)
{
	int		i;

	i = 0;
	if (!lol)
		return (0);
	while (lol[i])
		i++;
	i--;
	while (lol[i] == '.')
	{
		lol[i] = '\0';
		i--;
	}
	return (i);
}

char		*iden(char *dub)
{
	int		i;
	int		len;
	int		g;
	char	*c;

	i = 0;
	g = 0;
	c = dub;
	if (!dub)
		return (NULL);
	len = back(dub);
	while (dub[i] == '.')
	{
		i++;
		if (dub[i] == '\0')
			len = i;
	}
	while (i <= len)
		c[g++] = dub[i++];
	c[g] = '\0';
	return (c);
}

char		*resize(char *s, int j)
{
	int		k;
	int		n;

	k = 0;
	n = 0;
	while (s[n])
	{
		if (s[n] == '.')
		{
			while (s[n] == '.')
				n++;
			k++;
		}
		n++;
	}
	return (j < 0) ? getsmaller(s, k, j) : getbigger(s, k, j);
}

char		*getsmaller(char *s, int k, int j)
{
	int		i;
	int		n;
	char	*new;
	char	*lol;

	n = 0;
	i = -j;
	if (!(new = (char*)malloc(sizeof(char) * (ft_strlen(s) - (k * i) + 1))))
		return (0);
	lol = new;
	while (*s)
	{
		i = -j;
		while (*s == '.')
		{
			if (i != 0 && *s++ == '.')
				i--;
			else
				lol[n++] = *s++;
		}
		lol[n++] = *s++;
	}
	lol[n] = '\0';
	ft_strdel(&new);
	return (lol);
}

char		*getbigger(char *s, int k, int j)
{
	int		n;
	int		i;
	char	*new;
	char	*lol;

	n = 0;
	if (!(new = (char*)malloc(sizeof(char) * (ft_strlen(s) + (k * j) + 1))))
		return (0);
	lol = new;
	while (*s)
	{
		i = j;
		while (*s == '.')
		{
			lol[n++] = *s;
			while (i-- > 0)
				lol[n++] = '.';
			s++;
		}
		lol[n++] = *s;
		s++;
	}
	lol[n] = '\0';
	ft_strdel(&new);
	return (lol);
}
