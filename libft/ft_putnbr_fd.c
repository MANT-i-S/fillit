/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:10:23 by tebatsai          #+#    #+#             */
/*   Updated: 2019/05/13 21:51:10 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == -2147483648)
		{
			ft_putchar_fd('2', fd);
			ft_putnbr_fd(147483648, fd);
		}
		n = -n;
	}
	if (n >= 10)
	{
		if (n == 2147483647)
		{
			ft_putchar_fd('2', fd);
			ft_putnbr_fd(147483647, fd);
		}
		else if (n != 2147483647)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putchar_fd((n % 10) + '0', fd);
		}
	}
	else if (n != -2147483648)
		ft_putchar_fd(n + '0', fd);
}
