/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:21:39 by plinscho          #+#    #+#             */
/*   Updated: 2023/09/25 17:08:47 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void handler(int signal, siginfo_t *info, void *context)
{
	static char	received_char = 0;
	static int	bit_count = 0;
    if (signal == SIGUSR1 || signal == SIGUSR2)
    {
        received_char |= (signal == SIGUSR1 ? (1 << bit_count) : 0);
        bit_count++;

        if (bit_count == 8)
        {
            ft_printf("Received character: %c\n", received_char);
            received_char = 0;
            bit_count = 0;
        }
    }
}

int main(void)
{
    pid_t pid;
    struct sigaction sa;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler;

    pid = getpid();
    ft_printf("Server pid: %d\n", pid);
    if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        ft_printf("Error\n");
        exit(1);
    }

    while (1)
        sleep(1);
    return (0);
}
