/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:47:34 by nwai-kea          #+#    #+#             */
/*   Updated: 2022/12/01 17:08:06 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		i;
	char	*num;

	i = 0;
	num = ft_itoa(n);
	i = ft_putstr(num);
	free(num);
	return (i);
}

int	ft_numlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	char	*result;
	int		len;

	len = ft_numlen(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	result[len--] = '\0';
	while (n != 0)
	{
		result[len--] = n % 10 + '0';
		n /= 10;
	}
	return (result);
}

int	ft_putunbr(unsigned int n)
{
	int		len;
	char	*num;

	len = 0;
	if (n == 0)
		len += ft_putchar('0');
	else
	{
		num = ft_utoa(n);
		len += ft_putstr(num);
		free(num);
	}
	return (len);
}
