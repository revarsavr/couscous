# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 11:12:56 by daarriba          #+#    #+#              #
#    Updated: 2020/02/26 18:44:20 by daarriba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRCS = ft_checks.c ft_find.c ft_load.c ft_numbers.c main.c

OBJS = $(SRCS:.c=.o)

CC = gcc

RM = rm -f

FLAGS = -c -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRCS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	$(RM) std_input.txt

fclean: clean
	$(RM) $(NAME)

re: fclean all