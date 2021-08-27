#include "../header_files/minitalk.h"

void	error(int error)
{
	ft_putstr_fd("\033[0;31m", 1);
	if (error == 0)
		ft_putstr_fd("!Wrong server PID!\n", 1);
	if (error == 1)
		ft_putstr_fd("!Wrong number of parameters!\n", 1);
	ft_putstr_fd("Please execute \"client\" as following:\n", 1);
	ft_putstr_fd("[./client <ServerPID> <String>]\n", 1);
	ft_putstr_fd("\033[0m", 1);
}

void	send_char(char c, int server_pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c % 2)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		c /= 2;
		i++;
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;

	server_pid = ft_atoi(argv[1]);
	if (argc == 3)
		while (*argv[2])
			send_char(*argv[2]++, server_pid);
	else
		error(1);
}
