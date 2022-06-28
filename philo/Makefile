NAME			= philo

SRCS			= checks.c init.c main.c routine.c utils.c \
				  includes/ft_atoi.c

HEADER			= includes/philo.h

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -rf
CFLAGS			= -pthread -Wall -Wextra #-Werror

.PHONY:			all clean fclean re

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(OBJS) -o $(NAME)

%.o:			%.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@ 

clean:			
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all