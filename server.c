/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:54:29 by wbousfir          #+#    #+#             */
/*   Updated: 2023/04/16 18:23:57 by wbousfir         ###   ########.fr       */
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
		write(1, "-2147483648", 10);
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

size_t	ft_strlen(const char *s)
{
	size_t	b;

	b = 0;
	while (s[b] != '\0')
		b++;
	return (b);
}

void	receive_signal(int signal, siginfo_t *string, void *context)
{
	static int	max_bytes;
	static char	c;
	static int	pid;

	context = NULL;
	if (pid != string->si_pid)
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
}

int	main(int argc, char **argv)
{
	struct sigaction	string;

	*argv = 0;
	if (argc > 1)
	{
		write(1, "Error Don't put any arguments\n", 10);
		return (0);
	}
	ft_putnbr(getpid());
	//signal(SIGUSR1, receive_signal);
	//signal(SIGUSR2, receive_signal);
	string.sa_flags = SA_SIGINFO;
	string.sa_sigaction = &receive_signal;
	sigaction(SIGUSR1, &string, NULL);
	sigaction(SIGUSR2, &string, NULL);
	while (1)
	{
	}
	return (0);
}
