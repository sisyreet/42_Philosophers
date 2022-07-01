# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/01 18:56:09 by sisyreet          #+#    #+#              #
#    Updated: 2022/07/01 19:00:30 by sisyreet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= philo_bonus

SRCS			= init_bonus.c main_bonus.c start_bonus.c utils_bonus.c checks_bonus.c \
				semaphores_check_bonus.c

HEADER			= philo_bonus.h

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror -pthread
SANITIZE		= -fsanitize=thread

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