/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:23:00 by plinscho          #+#    #+#             */
/*   Updated: 2023/09/25 16:59:34 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	check_args(int argc, char **argv);
void	send_message(int pid, const char *msg);

int main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				pid;
	
	ft_printf("Client Pid: %d\n", getpid());
	check_args(argc, argv);
	pid = ft_atoi(argv[1]);
	send_message(pid, argv[2]);
	return (0);
	
}

void	check_args(int argc, char **argv)
{
	int	i;

	if (argc != 3)
	{
		ft_printf("Argument error\n");
		exit (1);
	}
	i = 0;
	while (argv[1][i])
	{
		if (!(ft_isdigit(argv[1][i])))
		{
			ft_printf("Pid not valid!\n");
			exit (1);
		}
		i++;
	}
	if (*argv[2] == 0)
	{
		ft_printf("Error\nEmpty message\n");
		exit (2);
	}
}

void	send_message(int s_pid, const char *msg)
{
	int		i;
	char	c;
	int		bit;

	i = 0;
	while(msg[i])
	{
		c = msg[i];
		bit = 0;
		while (bit < 8)
		{
			if ((c >> bit) & 1)
				kill(s_pid, SIGUSR1);
			else
				kill(s_pid, SIGUSR2);
			bit++;
			usleep(100);
		}
		usleep(1000);
		i++;
	}
	return ;
}
