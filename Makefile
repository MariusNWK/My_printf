##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## projet solo 1
##

NAME	=	libmy.a

all:
	$(MAKE) -C ./lib/my/

clean:
	$(RM) ./lib/my/*~
	$(MAKE) -C ./lib/my/ clean
	$(MAKE) -C ./tests/ clean

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) -C ./lib/my/ fclean
	$(MAKE) -C ./tests/ fclean

re:	fclean all

tests_run: fclean all
	$(MAKE) -C ./tests

.Phony: all clean fclean re
