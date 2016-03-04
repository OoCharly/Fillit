NAME = fillit

SRC = read.c verify_neighbors.c helpers.c tetros_to_left.c \
	solve.c main.c

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
