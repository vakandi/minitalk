/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:50:55 by wbousfir          #+#    #+#             */
/*   Updated: 2023/04/16 18:50:23 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int	ft_check_pid(char *str)
{
	int i;
	int check;

	i = 0;
	check = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 49 && str[i] < 57)
			check = 1;
		else
		{
			check = 0;
			break;
		}	
		i++;
	}
	return(check);
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

void	send_signal(int c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	x;
	int pid;

	x = 0;
	if (argc == 3)
	{
		if ((ft_check_pid(argv[1])) == 0)
		{
			write(1, "Error.pid, character in it\n", 27);
			return (0);
		}
		else
		{
			pid = ft_atoi(argv[1]);
			if (pid < 3)
				return (write(1, "Error.pid\n", 10));
			while (argv[2][x] != '\0')
			{
				send_signal((int)argv[2][x], ft_atoi(argv[1]));
				x++;
			}
			send_signal('\n', ft_atoi(argv[1]));
		}
	}
	else
		write(1, "Failed not enough argument", 26);
	return (0);
}
