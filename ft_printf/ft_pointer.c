/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:15:24 by nwai-kea          #+#    #+#             */
/*   Updated: 2022/11/29 20:54:07 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrlen(size_t ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (1);
	while (ptr != 0)
	{
		len++;
		ptr /= 16;
	}
	return (len);
}

int	ft_pointer(size_t ptr)
{
	int		len;
	int		remainder;
	int		i;
	char	c[20];

	len = 0;
	i = 0;
	len += write(1, "0x", 2);
	if (ptr == 0)
		len += ft_putchar('0');
	else
	{
		len += ft_ptrlen(ptr);
		while (ptr > 0)
		{
			remainder = ptr % 16;
			c[i] = SMALL_HEX[remainder];
			ptr /= 16;
			i++;
		}
		while (i--)
			ft_putchar(c[i]);
	}
	return (len);
}
