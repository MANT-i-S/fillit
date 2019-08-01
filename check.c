/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 16:07:21 by tebatsai          #+#    #+#             */
/*   Updated: 2019/07/03 16:58:00 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*build(char l, char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '#')
			s[i] = l;
		i++;
	}
	s[i] = '\0';
	return (s);
}

char		*kicker(int i, char *c, char *s)
{
	int		j;

	j = 0;
	while (s[i])
	{
		if (c[j] == '#' && s[i] == '.')
		{
			s[i] = c[j];
			j++;
		}
		if (ft_isalpha(s[i]) && c[j] == '.')
		{
			j++;
		}
		if (s[i] == '.' && c[j] == '.')
		{
			s[i] = c[j];
			j++;
		}
		if (c[j] == '\0')
			return (s);
		i++;
	}
	return (NULL);
}

char		*filler(char *yes, int i)
{
	int		l;

	l = i * i;
	yes[l--] = '\0';
	while (l >= 0)
	{
		yes[l] = '.';
		l--;
	}
	return (yes);
}

char		*news(char c, char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= c)
		{
			s[i] = '.';
		}
		i++;
	}
	s[i] = '\0';
	return (s);
}

void		finishthework(char **arr, char *lol)
{
	int		i;
	char	*yes;
	int		tetriminos;

	i = 0;
	tetriminos = g_tetriminos;
	g_square++;
	while ((g_square * g_square) < (tetriminos * 4))
		g_square++;
	yes = filler(ft_strnew((g_square * g_square)), g_square);
	while (!(i))
	{
		if ((match(arr, yes, 0, 1)))
		{
			print_answer(yes);
			i = 1;
		}
		ft_strdel(&yes);
		g_square++;
		yes = filler(ft_strnew((g_square * g_square)), g_square);
	}
	ft_strdel(&yes);
	ft_strdel(&lol);
	while (arr[i])
		ft_strdel(&arr[i++]);
}
