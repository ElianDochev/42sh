##
## EPITECH PROJECT, 2022
## minishell2 Makefile
## File description:
## compiles and builds lib and the source files runs unit tests
##

NAME	=	mysh

SRC	=	source/w_arr.c				\
		source/cd_command.c			\
		source/delims.c				\
		source/input_manager.c		\
		source/exec_binary.c		\
		source/exec_bin_extra.c		\
		source/find_in_word_arr.c	\
		source/env.c				\
		source/env_mod.c			\
		source/left_assos.c			\
		source/right_assos.c		\
		source/signa_and_pipes.c	\
		source/pipe_command.c		\
		source/parcer.c				\
		source/echo.c				\
		source/logical_opps.c

SRC_MAIN = source/main.c

CPPFLAGS =  -g3 -I./include

OBJ	=	$(SRC:.c=.o)

OBJ_MAIN = $(SRC_MAIN:.c=.o)

LIB 	=	-lmy -lprint

DIR	=	-L./lib/

TESTS = ##tests/

TEST_OBJ = $(TESTS:.c=.o)

LIB_TEST = libutest.a

TEST_INCLUDE = -L./ -lmy --coverage -lcriterion

TEST_NAME = unit_test

all: $(OBJ) $(OBJ_MAIN)
	$(MAKE) -C ./lib/my
	$(MAKE) -C ./lib/printf
	gcc -o $(NAME) $(OBJ) $(OBJ_MAIN) $(DIR) $(LIB)

clean:
	rm -f $(OBJ) $(OBJ_MAIN)
	$(MAKE) clean -C ./lib/my
	$(MAKE) clean -C ./lib/printf

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./lib/my
	$(MAKE) fclean -C ./lib/printf

re: fclean all

unit_tests: fclean $(OBJ) $(TEST_OBJ)
		$(MAKE) -C ./lib/my
		$(MAKE) -C ./lib/printf
		ar rc $(LIB_TEST) $(OBJ)
		gcc -o $(TEST_NAME) $(TESTS) $(TEST_INCLUDE)

tests_run: unit_tests
			./$(TEST_NAME)

unit_clean: fclean
			rm -f $(LIB_TEST)
			rm -f unit_test*
			rm -f $(TEST_OBJ)

.PHONY: all makelib clean fclean re
