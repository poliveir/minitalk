#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "../libft/libft.h"
# include <signal.h>

char			*add_to_str(char *str, char c);

void			error(int error);

void			handle_signals(int sig);

void			send_char(unsigned char c, int pid);

void			handle_signal(int sig);

#endif
