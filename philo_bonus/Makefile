NAME			= philo_bonus

SRCS			= main_bonus.c utils_bonus.c init_bonus.c checks_bonus.c \
				start_dinner_bonus.c thread_checks_bonus.c \
				includes/ft_atoi.c

HEADER			= includes/philo_bonus.h

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -rf
CFLAGS			= -pthread -g -Wall -Wextra -Werror

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