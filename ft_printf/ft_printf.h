/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:07:46 by nwai-kea          #+#    #+#             */
/*   Updated: 2022/12/01 15:46:42 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define SMALL_HEX "0123456789abcdef"
# define BIG_HEX "0123456789ABCDEF"

int		ft_printf(const char *str, ...);

int		ft_format(va_list args, const char f);

void	ft_putchar_fd(char c, int fd);

int		ft_putchar(int c);

int		ft_count(long int n);

char	*ft_itoa(int n);

int		ft_putstr(char *str);

int		ft_putnbr(int n);

int		ft_numlen(unsigned int n);

char	*ft_utoa(unsigned int n);

int		ft_putunbr(unsigned int n);

int		ft_hexlen(unsigned int num);

int		ft_hex(unsigned int num, const char f);

int		ft_pointer(size_t ptr);

int		ft_ptrlen(size_t ptr);

#endif