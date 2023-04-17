/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:49:32 by wbousfir          #+#    #+#             */
/*   Updated: 2023/04/17 21:54:37 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = n * -1;
		}
		if (n > 9)
		{
			ft_putnbr(n / 10);
		}
		ft_putchar((n % 10) + '0');
	}
}

void	receive_signal(int signal, siginfo_t *info, void *context)
{
	static char	c;
	static int	pid;
	static int	max_bytes;

	context = NULL;
	if (pid != info->si_pid)
	{
		max_bytes = 0;
		c = 0;
	}
	if (signal == SIGUSR1)
		c = c | (0x01 << max_bytes);
	max_bytes++;
	if (max_bytes == 8)
	{
		write(1, &c, 1);
		max_bytes = 0;
		c = 0;
	}
	pid = info->si_pid;
}

int	main(int argc, char **argv)
{
	struct sigaction	info;

	(void)argv;
	if (argc != 1)
		return (write(1, "[Error] : Too much argument\n", 26));
	ft_putnbr(getpid());
	write(1, "\n", 1);
	info.sa_flags = SA_SIGINFO;
	info.sa_sigaction = &receive_signal;
	sigaction(SIGUSR1, &info, NULL);
	sigaction(SIGUSR2, &info, NULL);
	while (1)
	{
	}
	return (0);
}
