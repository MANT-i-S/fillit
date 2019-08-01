/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   again.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:22:43 by tebatsai          #+#    #+#             */
/*   Updated: 2019/07/03 16:59:18 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			match(char **arr, char *s, int lol, int fibonacci)
{
	int		i;
	int		y;

	if (lol == g_tetriminos)
		return (1);
	y = g_square - 4;
	if (shapechecker(arr, iden(arr[lol])) && y < 0)
		if (smaller(iden(arr[lol]), s, arr))
			return (1);
	while (fibonacci < (int)ft_strlen(s))
	{
		if (changer(resize(iden(arr[lol]), y), s, fibonacci, 0))
		{
			i = check_this(resize(iden(arr[lol]), y), s, fibonacci, 0);
			build('A' + lol, kicker(i, resize(iden(arr[lol]), y), s));
			if (match(arr, s, ++lol, 1))
				return (1);
			else
				news('A' + (--lol), s);
		}
		fibonacci++;
	}
	return (0);
}

int			double_check_this(char *c, char *s, int *id, int j)
{
	j = hash_counter(c, D);
	return ((c[D] == '.' && (ft_isalpha(s[I]) || s[I] == '.'))
			|| ((c[D] == '#' && s[I] == '.'
					&& I % g_square + j <= g_square))) ? 1 : 0;
}

int			check_this(char *c, char *s, int t, int j)
{
	int		id[2];

	I = 0;
	D = 0;
	while (s[I])
	{
		while (double_check_this(c, s, id, j))
		{
			I++;
			D++;
			if (c[D] == '\0' && t != 1)
			{
				I -= D - 1;
				t--;
				D = 0;
			}
			if (c[D] == '\0' && t == 1)
				return (I - D);
		}
		I -= D;
		D = 0;
		I++;
	}
	return (0);
}

int			hash_counter(char *c, int d)
{
	int		i;

	i = 0;
	while (c[d] == '#')
	{
		i++;
		d++;
	}
	return (i);
}

int			changer(char *c, char *s, int t, int j)
{
	int		id[2];

	I = 0;
	D = 0;
	while (s[I])
	{
		while (double_check_this(c, s, id, j))
		{
			I++;
			if (c[++D] == '\0' && t != 1)
			{
				I -= D - 1;
				t--;
				D = 0;
			}
			if (c[D] == '\0' && t == 1)
				return (1);
		}
		I -= D;
		D = 0;
		if ((ft_strlen(c) + I) > ft_strlen(s))
			return (0);
		I++;
	}
	return (0);
}
