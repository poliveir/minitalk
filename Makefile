#VARIABLES:

LIBFT_PATH		= ./libft

NAME			= libminitalk.a

SRCS_DIR		= ./source_files

HDRS_DIR		= ./header_files

SERVER_SRC		= source_files/server.c

BONUS_SERVER_SRC	= source_files//server_bonus.c

CLIENT_SRC		= source_files/client.c

BONUS_CLIENT_SRC	= source_files/client_bonus.c

LIBFT_SRCS		= libft/ft_atoi.c libft/ft_atol.c libft/ft_isascii.c libft/ft_memchr.c libft/ft_putchar_fd.c libft/ft_strchr.c \
			  libft/ft_strlen.c libft/ft_strtrim.c libft/ft_bzero.c libft/ft_isdigit.c libft/ft_memcmp.c \
			  libft/ft_putendl_fd.c libft/ft_strdup.c libft/ft_strmapi.c libft/ft_substr.c libft/ft_calloc.c \
			  libft/ft_isprint.c libft/ft_memcpy.c libft/ft_putnbr_fd.c libft/ft_strjoin.c libft/ft_strncmp.c \
			  libft/ft_tolower.c libft/ft_isalnum.c libft/ft_itoa.c libft/ft_memmove.c libft/ft_putstr_fd.c \
			  libft/ft_strlcat.c libft/ft_strnstr.c libft/ft_toupper.c libft/ft_isalpha.c libft/ft_memccpy.c \
			  libft/ft_memset.c libft/ft_split.c libft/ft_strlcpy.c libft/ft_strrchr.c libft/ft_lstnew.c \
			  libft/ft_lstadd_front.c libft/ft_lstsize.c libft/ft_lstlast.c libft/ft_lstadd_back.c \
			  libft/ft_lstdelone.c libft/ft_lstclear.c libft/ft_lstiter.c libft/ft_lstmap.c

LIBFT_OBJS		= ${LIBFT_SRCS:.c=.o}

CC			= gcc

CFLAGS			= -fsanitize=address -Wall -Werror -Wextra

AR			= ar

ARFLAGS			= -rcs

RM			= rm -rf

#RULES:

.SILENT:
all: ${NAME} ${SERVER_SRC} ${CLIENT_SRC}


$(NAME):
	${MAKE} re bonus -C ${LIBFT_PATH}
	mv libft/libft.a . && mv libft.a libminitalk.a
	$(CC) ${CFLAGS} ${SERVER_SRC} ${NAME} -o server
	$(CC) ${CFLAGS} ${CLIENT_SRC} ${NAME} -o client

.SILENT:
bonus:
	${MAKE} re bonus -C ${LIBFT_PATH}
	mv libft/libft.a . && mv libft.a libminitalk.a
	$(CC) ${CFLAGS} ${BONUS_SERVER_SRC} ${NAME} -o server_bonus
	$(CC) ${CFLAGS} ${BONUS_CLIENT_SRC} ${NAME} -o client_bonus

clean:
	${RM} *.o ${SRCS_DIR}/*.o
	${MAKE} clean -C ${LIBFT_PATH}

fclean: clean
	${RM} ${NAME} server client server_bonus client_bonus
	${MAKE} fclean -C ${LIBFT_PATH}

re: fclean all

.PHONY: all clean fclean re
