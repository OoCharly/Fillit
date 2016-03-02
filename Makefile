# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/08 18:14:13 by dgaitsgo          #+#    #+#              #
#    Updated: 2016/02/25 12:23:13 by dgaitsgo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = parse_fillit.c verify_fillit.c helpers_fillit.c tests_fillit.c \
	solve_fillit.c prep_solution.c

OBS = $(SRC:.c=.o)

LIB = ./libft/libft.a

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRC)
	gcc -o $(NAME) $(OBS) $(LIB)

clean:
	rm -rf $(OBS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
