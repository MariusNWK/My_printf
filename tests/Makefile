##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	unit_tests

CFLAGS	=	-I ../includes/

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(SRC) ../libmy.a $(CFLAGS) -lcriterion -coverage
	./$(NAME)
	gcovr

clean:
	$(RM) *.o
	$(RM) *.gcda
	$(RM) *.gcno

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.Phony: all clean fclean re
