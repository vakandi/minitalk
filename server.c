/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:54:29 by wbousfir          #+#    #+#             */
/*   Updated: 2023/04/11 20:54:30 by wbousfir         ###   ########.fr       */
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

void	receive_signal(int signal)
{
	static int	max_bytes;
	static char	c;

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
	*argv = 0;
	if (argc > 1)
	{
		write(1, "Error Don't put any arguments\n", 10);
		return (0);
	}
	ft_putnbr(getpid());
	signal(SIGUSR1, receive_signal);
	signal(SIGUSR2, receive_signal);
	while (1)
	{
	}
	return (0);
}
