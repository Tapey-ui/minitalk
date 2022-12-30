/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:32:57 by nwai-kea          #+#    #+#             */
/*   Updated: 2022/11/29 20:55:11 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

int	ft_hex(unsigned int num, const char f)
{
	int		len;
	int		remainder;
	int		i;
	char	c[20];

	i = 0;
	len = ft_hexlen(num);
	if (num == 0)
		ft_putchar('0');
	while (num > 0)
	{
		remainder = num % 16;
		if (f == 'x')
			c[i] = SMALL_HEX[remainder];
		else
			c[i] = BIG_HEX[remainder];
		num /= 16;
		i++;
	}
	while (i--)
		ft_putchar(c[i]);
	return (len);
}
