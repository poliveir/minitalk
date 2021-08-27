#include "../header_files/minitalk.h"

void	handle_signals(int sig)
{
	static int	c = 0;
	static int	bits = 0;

	if (sig == SIGUSR1)
		c += (1 << bits++);
	else if (sig == SIGUSR2)
		bits++;
	if (bits == 8)
	{
		ft_putchar_fd(c, 1);
		c = 0;
		bits = 0;
	}
}

int	main(void)
{
	ft_putstr_fd("\033[0;32m", 1);
	ft_putstr_fd("|Server initialized|\n", 1);
	ft_putstr_fd("\033[0;33m", 1);
	ft_putstr_fd("[SERVER_PID]-> ", 1);
	ft_putstr_fd("\033[0m", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
		signal(SIGUSR1, handle_signals);
		signal(SIGUSR2, handle_signals);
		pause();
	}
	return (0);
}
