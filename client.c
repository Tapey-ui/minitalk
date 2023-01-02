/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:33:35 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/01/02 13:17:29 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

static void	action(int sig)
{
	if (sig == SIGUSR2)
	{
		write(1, "SUCCESS!\n", 9);
		exit(0);
	}
}

static void	ft_sendchar(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c >> bit & 0x01)
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(2, "Invalid PID!\n", 13);
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(2, "Invalid PID!\n", 13);
				exit(1);
			}
		}
		bit++;
		usleep(100);
	}
}

static void	ft_send(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_sendchar(pid, str[i]);
		i++;
	}
	i = -1;
	while (++i < 8)
	{
		kill(pid, SIGUSR1);
		usleep(20);
	}
}

int	main(int argc, char **argv)
{
	int	len;
	int	id;

	if (argc != 3)
	{
		ft_printf("ERROR! Please send in format (program [id] [message])!");
		return (0);
	}
	len = ft_strlen(argv[2]);
	if (!len)
	{
		ft_printf("ERROR! Please send in format (program [id] [message])!");
		return (0);
	}
	ft_printf("Sent		: %d\n", len);
	signal(SIGUSR2, action);
	id = ft_atoi(argv[1]);
	ft_send(id, argv[2]);
	while (1)
		pause();
	return (0);
}
