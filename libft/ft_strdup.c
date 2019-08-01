/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 17:36:32 by tebatsai          #+#    #+#             */
/*   Updated: 2019/05/10 18:52:54 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		j;
	char	*s;

	j = 0;
	i = 0;
	while (str[i])
		i++;
	if (!(s = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	while (j != i)
	{
		s[j] = str[j];
		j++;
	}
	s[j] = '\0';
	return (s);
}
