#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include <signal.h>

void	error(int error);

void	send_char(char c, int pid);

void	handle_signals(int sig);

#endif
