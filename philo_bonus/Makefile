# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 11:55:42 by haghouli          #+#    #+#              #
#    Updated: 2023/02/11 14:27:54 by haghouli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SANI			= -fsanitize=address
SANI_TH			= -fsanitize=pthread
COLOR_GREEN		= \033[0;32m
F_THREAD		= -g -pthread
NAME			= philo
CC				= cc
CFLAGS 			= -Wall -Wextra -Werror

FILES			= ./main.c \
				./ft_atoi.c \
				./check_errors.c \
				./utiles.c \
				./inits.c \
				./routines.c

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
