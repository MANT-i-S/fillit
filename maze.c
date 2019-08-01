/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 23:57:38 by tebatsai          #+#    #+#             */
/*   Updated: 2019/07/01 23:57:43 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			dial(int i)
{
	return (i == 1000110001 || i == 10011001 || i == 1100011
			|| i == 11011 || i == 1111 || i == 2001 || i == 1000111
			|| i == 10111 || i == 110010001 || i == 1100010001
			|| i == 100111 || i == 100011001 || i == 111001
			|| i == 100110001 || i == 110011 || i == 1000100011
			|| i == 11101 || i == 1110001 || i == 100010011) ? 1 : 0;
}

int			shapechecker(char **arr, char *c)
{
	if (ft_strcmp(c, "##..##") == 0 && !arr[1])
		return (1);
	if (ft_strcmp(c, "#.###") == 0 && !arr[1])
		return (8);
	if (ft_strcmp(c, "###.#") == 0 && !arr[1])
		return (9);
	if (ft_strcmp(c, "##..##") == 0 && ft_strcmp(iden(arr[1]), "###.#") == 0)
		return (2);
	if (ft_strcmp(c, "##..##") == 0 && ft_strcmp(iden(arr[1]), "#.###") == 0)
		return (3);
	if (ft_strcmp(c, "###.#") == 0 && ft_strcmp(iden(arr[1]), "#.###") == 0)
		return (4);
	if (ft_strcmp(c, "#.###") == 0 && ft_strcmp(iden(arr[1]), "###.#") == 0)
		return (5);
	if (ft_strcmp(c, "#.###") == 0 && ft_strcmp(iden(arr[1]), "##..##") == 0)
		return (6);
	if (ft_strcmp(c, "###.#") == 0 && ft_strcmp(iden(arr[1]), "##..##") == 0)
		return (7);
	if (ft_strcmp(c, "##.##") == 0 && !arr[1])
		return (10);
	if (ft_strcmp(c, "##.##") == 0 && ft_strcmp(iden(arr[1]), "#.###") == 0)
		return (11);
	return (0);
}

char		*tworabbit(int f, int i, char **arr, char *s)
{
	return (build('A', kicker(f, resize(iden(arr[0]), -1),
					build('B', kicker(i, resize(iden(arr[1]), -1), s)))));
}

char		*smaller(char *c, char *s, char **arr)
{
	if (ft_strlen(s) == 4 && shapechecker(arr, c) == 1)
		return (build('A', ft_strcpy(s, resize(c, -2))));
	if (ft_strlen(s) == 9 && shapechecker(arr, c) == 2)
		return (tworabbit(4, 0, arr, s));
	if (ft_strlen(s) == 9 && shapechecker(arr, c) == 3)
		return (tworabbit(0, 5, arr, s));
	if (ft_strlen(s) == 9 && shapechecker(arr, c) == 4)
		return (tworabbit(0, 5, arr, s));
	if (ft_strlen(s) == 9 && shapechecker(arr, c) == 5)
		return (tworabbit(5, 0, arr, s));
	if (ft_strlen(s) == 9 && shapechecker(arr, c) == 6)
		return (tworabbit(5, 0, arr, s));
	if (ft_strlen(s) == 9 && shapechecker(arr, c) == 7)
		return (tworabbit(0, 4, arr, s));
	if (ft_strlen(s) == 9 && shapechecker(arr, c) == 8)
		return (build('A', kicker(2, resize(c, -1), s)));
	if (ft_strlen(s) == 9 && shapechecker(arr, c) == 9)
		return (build('A', kicker(0, resize(c, -1), s)));
	if (ft_strlen(s) == 9 && shapechecker(arr, c) == 10)
		return (build('A', kicker(1, resize(c, -1), s)));
	if (ft_strlen(s) == 9 && shapechecker(arr, c) == 11)
		return (tworabbit(1, 5, arr, s));
	else
		return (NULL);
}
