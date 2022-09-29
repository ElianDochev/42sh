##
## EPITECH PROJECT, 2022
## Makefile for lib
## File description:
## Compiles and builds mylib (called from root Makefile)
##

SCR	=	str_to_int.c	\
		str_dup.c		\
		str_cat.c		\
		error.c			\
		square_root.c   \
		comp_strs.c		\
		hash_table.c	\
		linked_list.c	\
		open_file.c		\
		delete_two_d_string.c	\
		remove_seps.c			\
		split_str.c

OBJ	=	$(SCR:.c=.o)

CPPFLAGS = -Wall -Wextra -I../../include

NAME	=	libmy.a

all: $(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../

clean:
	rm -f $(OBJ)

fclean: clean
	   rm -f ../$(NAME)

re: fclean all

.PHONY: all makelib clean fclean re
