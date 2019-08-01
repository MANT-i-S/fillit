/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 10:21:24 by tebatsai          #+#    #+#             */
/*   Updated: 2019/07/03 17:41:20 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**get_array(int fd, int k)
{
	int		id[2];
	char	**arr;
	char	buff[1];

	arr = ft_create_arr(g_tetriminos, 16);
	I = 0;
	D = 0;
	while (read(fd, buff, 1))
	{
		if (k == 4)
		{
			k = 0;
			arr[I++][D] = '\0';
			D = 0;
		}
		else if (buff[0] == '\n')
			k++;
		else
			arr[I][D++] = buff[0];
	}
	if (k != 4 && D != 16)
		return (NULL);
	arr[I][D] = '\0';
	return (arr);
}

int			print_answer(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
		if (i % g_square == 0)
			ft_putchar('\n');
	}
	return (1);
}

void		finish_him(int l, int fd, char **arr, char *lol)
{
	int		i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			ft_strdel(&arr[i]);
			i++;
		}
	}
	ft_putstr("error\n");
	ft_strdel(&lol);
	close(fd);
	close(l);
}

int			main(int arc, char **arv)
{
	int		fd;
	char	**arr;
	char	*lol;
	int		l;

	if (arc == 2)
	{
		lol = ft_strdup(arv[1]);
		fd = open(arv[1], O_RDONLY);
		if (valid_square(fd))
		{
			l = open(lol, O_RDONLY);
			arr = get_array(l, 0);
			if (valid_file(arr))
				finishthework(arr, lol);
			else
				finish_him(l, fd, arr, lol);
		}
		else
			finish_him(0, fd, NULL, lol);
	}
	return (0);
}
