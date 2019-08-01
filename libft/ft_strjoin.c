/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 22:01:06 by tebatsai          #+#    #+#             */
/*   Updated: 2019/05/15 17:10:33 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*fresh;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	if (!(fresh = (char*)malloc(sizeof(char) * (i + j) + 1)))
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		fresh[i] = s1[i];
	while (s2[++j])
	{
		fresh[i] = s2[j];
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
