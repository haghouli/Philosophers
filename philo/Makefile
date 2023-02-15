# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 11:55:42 by haghouli          #+#    #+#              #
#    Updated: 2023/02/15 09:46:39 by haghouli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SANI			= -fsanitize=address
SANI_TH			= -fsanitize=thread -g -O1
COLOR_GREEN		= \033[0;32m
F_THREAD		= -g -pthread
NAME			= philo
CC				= cc
CFLAGS 			= -Wall -Wextra -Werror

FILES			= ./main.c \
				./ft_atoi.c \
				./check_errors.c \
				./inits.c \
				./utiles.c \
				./philosophers.c \
				./philosophers_2.c \
				./routines.c \
				./free_all.c

OBJS			= $(FILES:.c=.o)

all		: $(NAME)

$(NAME)	: $(OBJS)
	@$(CC) $(F_THREAD) $(CFLAGS) $(OBJS) -o $(NAME) $(SANI)

clean	:
	@rm -f $(OBJS)
	@echo "$(COLOR_GREEN)cleaning..."

fclean	: clean
	@rm -f $(NAME)

re		: fclean all 

%.o : %.c
	@$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@
	@echo "$(COLOR_GREEN)Making..."

push :
	git add . && git commit -m "..." && git push