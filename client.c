#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int     ft_atoi(const char *str)
{
        int     x;
        int     a;
        int     y;

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


void	send_signal(char c, int pid)
{
	int bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
	}
	usleep(500);
}

int	main(int argc, char **argv)
{
	int x;

	x = 0;
	if (argc == 3)
	{
		while(argv[2][x] != '\0')
		{
			send_signal(argv[2][x], ft_atoi(argv[1]));
			x++;
		}
	send_signal('\n', ft_atoi(argv[1]));
	}
	else
		write(1, "Failed not enough argument", 26);
		
	return(0);
}
