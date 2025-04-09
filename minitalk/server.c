/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raktas <raktas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:53:22 by raktas            #+#    #+#             */
/*   Updated: 2025/03/26 15:44:04 by raktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_handler(int sig, siginfo_t *info, void *ucontext)
{
	static int	bit = 0;
	static char	i = 0;

	(void)ucontext;
	if (sig == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		if (i == '\0')
			write(1, "\n", 1);
		bit = 0;
		i = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	act;

	(void)argv;
	if (argc != 1)
	{
		write(2, "Wrong format!!!", 17);
		return (1);
	}
	act.sa_sigaction = ft_handler;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	if (sigaction(SIGUSR1, &act, NULL) == -1
		|| sigaction(SIGUSR2, &act, NULL) == -1)
	{
		write(2, "Error: sigaction failed\n", 25);
		return (1);
	}
	ft_printf("Server is running...\n");
	ft_printf("ID: %d\n", getpid());
	ft_printf("Waiting for signals...\n");
	while (1)
		pause();
	return (0);
}
