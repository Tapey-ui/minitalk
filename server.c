/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:33:26 by nwai-kea          #+#    #+#             */
/*   Updated: 2022/12/30 17:39:38 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

static void	act(int sig, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	i = 0;

	(void)context;
	if (sig == SIGUSR2)
		c |= (1 << i);
	if (++i == 8)
	{
		i = 0;
		write(1, &c, 1);
		if (!c)
		{
			kill(info->si_pid, SIGUSR2);
			write(1, "\n", 1);
			info->si_pid = 0;
			return ;
		}
		c = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sig;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	sig.sa_sigaction = act;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, 0);
	sigaction(SIGUSR2, &sig, 0);
	while (1)
		pause();
	return (0);
}
