/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:56:11 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/04/11 16:41:05 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft.h"
#include "minitalk.h"

void	wrong_usage(void)
{
	write(1, "please insert: ./client [server-pid] [message]\n", 47);
	exit(0);
}

void	char_sender(int pid, unsigned char byte)
{
	int		counter;

	counter = 1 << 6;
	while (counter)
	{
		if (byte & counter)
		{
			if (kill(pid, SIGUSR1) == -1)
				error("wrong pid\n");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				error("wrong pid\n");
		}
		counter >>= 1;
		usleep(600);
	}
}

void	main_handler(char *str_pid, char *message)
{
	int			pid;

	pid = ft_atoi(str_pid);
	while (*message)
	{
		char_sender(pid, *message);
		++message;
	}
	char_sender(pid, *message);
}

void	success(int sig)
{
	(void)sig;
	write(1, "Server has received the data.\n", 30);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i == 0)
	{
		if (argc != 3)
			wrong_usage();
		else
		{
			signal(SIGUSR1, success);
			main_handler(argv[1], argv[2]);
		}
		i++;
	}
}
