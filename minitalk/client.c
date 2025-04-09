/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raktas <raktas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:52:51 by raktas            #+#    #+#             */
/*   Updated: 2025/03/26 15:37:56 by raktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_flag = 0;

static int	pid_control(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

static int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long int		result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return ((int)result * sign);
}

static void	flag_handler(int signal)
{
	if (signal == SIGUSR1)
		g_flag = 1;
}

static void	send_signal(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_flag)
			;
		g_flag = 0;
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

	if (argc != 3)
	{
		write(2, "Wrong format!!!\n", 17);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid_control(argv[1]) == 1 || pid == 0 || kill(pid, 0) == -1)
	{
		write(2, "Invalid PID\n", 13);
		return (1);
	}
	signal(SIGUSR1, flag_handler);
	message = argv[2];
	while (*message)
		send_signal(pid, *message++);
	send_signal(pid, '\0');
	return (0);
}
