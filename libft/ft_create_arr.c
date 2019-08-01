/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 20:24:54 by tebatsai          #+#    #+#             */
/*   Updated: 2019/05/15 20:57:48 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_create_arr(int x, int y)
{
	char	**sq;
	int		i;

	i = 0;
	sq = (char **)malloc(sizeof(char *) * (x + 1));
	while (i < x)
	{
		sq[i] = (char *)malloc(sizeof(char) * (y + 1));
		i++;
	}
	sq[i] = NULL;
	return (sq);
}
