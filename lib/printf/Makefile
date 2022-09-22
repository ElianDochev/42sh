##
## EPITECH PROJECT, 2022
## Makefile for lib
## File description:
## Compiles and builds mylib
##

SCR	=	source/my_strlen.c	\
		source/char_to_str.c  \
		source/to_upper.c \
		source/error.c	\
		source/my_compute_power_rec.c	\
		source/int_to_str.c	\
		source/int_to_str_unsigned.c	\
		source/base_ten_to_hex.c	\
		source/my_printf.c \
		source/flags_part_one.c	\
		source/flags_part_two.c	\
		source/flags_part_three.c	\
		source/flags_part_four.c	\
		source/rev_buff.c

OBJ	=	$(SCR:.c=.o)

CPPFLAGS = -I./include

NAME	=	libprint.a

all: $(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)

re: fclean all
