#include "../header_files/minitalk_bonus.h"

static int	g_c_pid = 0;

char	*add_to_str(char *str, char c)
{
	char	*temp;
	char	*s;

	if (c)
	{
		if (!str)
			str = ft_strdup("");
		temp = malloc(2);
		temp[0] = c;
		temp[1] = '\0';
		s = ft_strjoin(str, temp);
		free(str);
		free(temp);
		return (s);
	}
	else
	{
		g_c_pid = ft_atoi(str);
		free(str);
		str = NULL;
		return (str);
	}
}

void	handle_signals(int sig)
{
	static int				c = 0;
	static int				bits = 0;
	static char				*c_pid = NULL;

	if (sig == SIGUSR1)
		c += (1 << bits++);
	else if (sig == SIGUSR2)
		bits++;
	if (bits == 8)
	{
		if (!g_c_pid)
			c_pid = add_to_str(c_pid, c);
		else
		{
			if (c)
				ft_putchar_fd(c, 1);
			else
			{
				kill(g_c_pid, SIGUSR1);
				g_c_pid = 0;
			}
		}
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
