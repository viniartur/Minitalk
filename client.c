
#include "minitalk.h"

void	send_bit(int pid, unsigned char bit)
{
	if (bit == 0)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_putstr_fd("Error: failed to send signal\n", 2);
			exit(1);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_putstr_fd("Error: failed to send signal\n", 2);
			exit(1);
		}
	}
	usleep(100);
}

void	send_char(int pid, unsigned char c)
{
	int	i;
	
	i = 0;
	while (i < 8)
	{
		send_bit(pid, (c >> i) & 1);
		i++;
	}
}

void	send_string(int pid, char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		send_char(pid, (unsigned char)str[i]);
		i++;
	}
	send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	int	server_pid;
	
	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client [server_pid] [string]\n", 2);
		return (1);
	}
	
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_putstr_fd("Error: Invalid PID\n", 2);
		return (1);
	}
	
	send_string(server_pid, argv[2]);
	return (0);
}