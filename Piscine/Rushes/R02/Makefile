# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/23 10:21:48 by daarriba          #+#    #+#              #
#    Updated: 2020/02/23 20:16:14 by daarriba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

all: $(NAME)

$(NAME):
	cc -Wall -Wextra -Werror -o $(NAME) *.c

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all