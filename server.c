/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musoysal <musoysal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:43:33 by musoysal          #+#    #+#             */
/*   Updated: 2025/01/26 13:21:59 by musoysal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_bit = 0;

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static char	ch = 0;

	(void)context;
	if (signal == SIGUSR1)
		ch |= (1 << g_bit);
	g_bit++;
	if (g_bit == 8)
	{
		if (ch == '\0')
			kill(info->si_pid, SIGUSR1);
		else
			ft_printf("%c", ch);
		g_bit = 0;
		ch = 0;
	}
	if (kill(info->si_pid, SIGUSR2) == -1)
		ft_printf("\033[91mError: Failed to send ACK to client.\033[0m\n");
}

int	main(void)
{
	struct sigaction	sig;

	ft_printf("\033[94mServer PID:\033[0m \033[96m%d\033[0m\n", getpid());
	ft_printf("\033[90mWaiting for a message...\033[0m\n");
	sig.sa_sigaction = handle_signal;
	sig.sa_flags = SA_SIGINFO;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
