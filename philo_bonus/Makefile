NAME			= philo_bonus

SRCS			= init_bonus.c main_bonus.c start_bonus.c utils_bonus.c \
				semaphores_check_bonus.c includes/ft_atoi.c

HEADER			= includes/philo_bonus.h

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -rf
CFLAGS			= -pthread -Wall -Wextra -Werror

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