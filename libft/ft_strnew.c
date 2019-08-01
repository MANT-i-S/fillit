/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:28:48 by tebatsai          #+#    #+#             */
/*   Updated: 2019/05/03 20:49:30 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *c;

	if (!(c = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(c, size + 1);
	return (c);
}
