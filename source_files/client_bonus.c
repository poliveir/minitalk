#include "../header_files/minitalk_bonus.h"

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
	exit(0);
}

void	send_char(unsigned char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c % 2)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c /= 2;
		i++;
		usleep(50);
	}
}

void	handle_signal(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_putstr_fd("\033[0;32m", 1);
		ft_putstr_fd("[Message successfully sent]\n", 1);
		ft_putstr_fd("\033[0m", 1);
	}
	exit(0);
}

int	main(int argc, char **argv)
{
	char	*client_pid;

	signal(SIGUSR1, handle_signal);
	if (argc == 3 && ft_atoi(argv[1]) > 0 && ft_atoi(argv[1]) < 99999)
	{
		client_pid = ft_itoa(getpid());
		while (*client_pid)
			send_char(*client_pid++, ft_atoi(argv[1]));
		send_char('\0', ft_atoi(argv[1]));
		while (*argv[2])
			send_char(*argv[2]++, ft_atoi(argv[1]));
		send_char('\0', ft_atoi(argv[1]));
	}
	else
		error(1);
	pause();
}
