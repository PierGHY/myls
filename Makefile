##
## EPITECH PROJECT, 2019
## make
## File description:
## a
##

SRC     =   myls.c \
            lib.c \
			myls2.c \
			myls3.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

all:    $(NAME)

$(NAME):        $(OBJ)
		gcc -lm -g3 -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re