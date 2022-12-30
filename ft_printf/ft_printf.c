/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:26:41 by nwai-kea          #+#    #+#             */
/*   Updated: 2022/11/29 20:45:59 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_format(va_list args, const char f)
{
	int	result;

	result = 0;
	if (f == 'c')
		result += ft_putchar(va_arg(args, int));
	if (f == 'd' || f == 'i')
		result += ft_putnbr(va_arg(args, int));
	if (f == 'u')
		result += ft_putunbr(va_arg(args, unsigned int));
	if (f == 's')
		result += ft_putstr(va_arg(args, char *));
	if (f == 'x' || f == 'X')
		result += ft_hex(va_arg(args, unsigned int), f);
	if (f == 'p')
		result += ft_pointer(va_arg(args, size_t));
	if (f == '%')
		result += ft_putchar('%');
	return (result);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		result;
	int		i;

	result = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			result += ft_format(args, str[i + 1]);
			i++;
		}
		else
			result += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (result);
}
