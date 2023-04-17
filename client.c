/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:44:50 by wbousfir          #+#    #+#             */
/*   Updated: 2023/04/17 21:56:32 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int	ft_check_pid(char *str)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
			check = 1;
		else
		{
			check = 0;
			break ;
		}
		i++;
	}
	return (check);
}

int	ft_atoi(const char *str)
{
	int	x;
	int	a;
	int	y;

	y = 1;
	a = 0;
	x = 0;
	while ((str[x] >= 9 && str[x] <= 13) || str[x] == 32)
		x++;
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			y = -1;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		a = a * 10 + (str[x] - 48);
		x++;
	}
	return (a * y);
}

void	send_signal(int pid, char c)
{
	int	max_bytes;

	max_bytes = 0;
	while (max_bytes < 8)
	{
		if ((c & (1 << max_bytes)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		max_bytes++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid < 3)
			return (write(1, "[Error] : PID Permission Denied\n", 32));
		if ((ft_check_pid(argv[1])) == 0)
		{
			write(1, "[Error] : Character found in PID\n", 33);
			return (0);
		}
		while (argv[2][i] != '\0')
		{
			send_signal(pid, argv[2][i]);
			i++;
		}
	}
	else
		write(1, "[Error] : Not Enough Argumentsarg\n", 29);
	return (0);
}

