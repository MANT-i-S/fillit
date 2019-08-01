/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validatin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 10:34:36 by tebatsai          #+#    #+#             */
/*   Updated: 2019/07/01 22:23:35 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				is(char c)
{
	return (c == '#' || c == '.' || c == '\n') ? 1 : 0;
}

int				valid_square(int fd)
{
	int		id[2];
	char	buff[1];

	I = 0;
	D = 0;
	while ((read(fd, buff, 1) && (is(buff[0]))))
	{
		if (buff[0] == '\n')
		{
			D++;
			read(fd, buff, 1);
			if (I != 4 || !(is(buff[0])) || (D == 4 && buff[0] != '\n'))
				return (0);
			I = 1;
			if (D == 4 && buff[0] == '\n')
			{
				D = 0;
				g_tetriminos++;
				I = 0;
			}
		}
		else
			I++;
	}
	return (*buff == '\n' && D == 0) ? 1 : 0;
}

int				count_hash(char *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (*s == '#')
			i++;
		else if (*s == '.')
			j++;
		s++;
	}
	return (i == 4 && j == 12) ? 1 : 0;
}

int				face_hash(char *s)
{
	int		i;
	int		z;

	z = 0;
	i = 0;
	while (*s)
	{
		if (*s == '#')
		{
			if (z > 0)
				i *= 10;
			i++;
			z++;
		}
		else if (z == 4)
			return (dial(i));
		else if (i == 100010001)
			i = 2;
		else if (*s == '.')
			i *= 10;
		s++;
	}
	return (dial(i));
}

int				valid_file(char **s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (!(count_hash(s[i])) || !(face_hash(s[i])))
			return (0);
		i++;
	}
	return (1);
}
