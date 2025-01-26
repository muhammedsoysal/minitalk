/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musoysal <musoysal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:29:05 by musoysal          #+#    #+#             */
/*   Updated: 2025/01/26 13:06:17 by musoysal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_ack_received = 0;

void	confirm_ack(int signal)
{
	if (signal == SIGUSR2)
		g_ack_received = 1;
	else if (signal == SIGUSR1)
		ft_printf("\033[0;32mMessage received completely!\033[0m\n");
}

int	ft_atoi(const char *str)
{
	int	i;
	int	result;

	i = 1;
	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			i *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		result = result * 10 + *str - 48;
		str++;
	}
	return (result * i);
}

int	send_character(int pid, char ch)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_ack_received = 0;
		if ((ch >> bit) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (-1);
		}
		else
			if (kill(pid, SIGUSR2) == -1)
				return (-1);
		while (!g_ack_received)
			usleep(100);
		bit++;
	}
	return (0);
}

int	validate_args(int argc)
{
	if (argc != 3)
	{
		ft_printf("\033[91mError: Incorrect number of arguments.\033[0m\n");
		ft_printf("\033[33mUsage: ./client <PID> <MESSAGE>\033[0m\n");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (!validate_args(argc))
		return (1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0 || pid > 2147483647)
		return (1);
	signal(SIGUSR2, confirm_ack);
	signal(SIGUSR1, confirm_ack);
	i = 0;
	while (argv[2][i])
	{
		if (send_character(pid, argv[2][i++]) == -1)
		{
			ft_printf("\033[91mError: Failed to send character.\033[0m\n");
			return (1);
		}
	}	
	if (send_character(pid, '\0') == -1)
	{
		ft_printf("\033[91mError: Failed to send end-of-message signal.\033[0m\n");
		return (1);
	}
	return (0);
}
