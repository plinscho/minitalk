/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:21:39 by plinscho          #+#    #+#             */
/*   Updated: 2023/10/05 19:00:16 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	handler(int sig)
{
	static int				octet = 0;
	static unsigned char	c = '\0';

	c = c << 1;
	if (sig == SIGUSR1)
		c = c | 1;
	octet++;
	if (octet == 8)
	{
		ft_printf("%c", c);
		octet = 0;
		c = '\0';
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_handler = handler;
	pid = getpid();
	ft_printf("Server pid: %d\n", pid);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || \
		sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error\n");
		exit(1);
	}
	else
		ft_printf("String received succedfully\n");
	while (1)
		sleep(1);
	return (0);
}
