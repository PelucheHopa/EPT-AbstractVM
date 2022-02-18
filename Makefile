##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## abstractVm
##

SRC =		src/Main.cpp 	\
			src/FctPtr.cpp 	\
			src/Memory.cpp	\
			src/Factory.cpp	\
			src/types/Int8.cpp	\
			src/types/Int16.cpp \
			src/types/Int32.cpp	\
			src/types/Float.cpp	\
			src/types/Double.cpp	\
			src/Parser.cpp	\
			src/IO.cpp

OBJ =		$(SRC:.cpp=.o)

INCLUDE = 	-I include/ -I error/

NAME = 		abstractVM

CFLAGS = 	-W -Wextra -Wall

SRC_TESTS = $(wildcard src/types/*.cpp) \
			src/FctPtr.cpp	\
			src/Memory.cpp	\
			src/Parser.cpp	\
			src/Factory.cpp

TEST_FILES = $(wildcard tests/*.cpp)

all:		$(NAME)

$(NAME):
	g++ $(CFLAGS) -o $(NAME) $(SRC) $(INCLUDE) -g

clean:
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf $(OBJ)
	rm -rf vgcore.*
	rm -rf unit_tests

fclean:	clean
	rm -rf $(NAME)

re:			fclean all

test: clean
	g++ -o unit_tests $(SRC_TESTS) $(TEST_FILES) --coverage -lcriterion $(INCLUDE)
	./unit_tests

test_coverage:
	gcovr --exclude tests/

test_branches:
	gcovr --exclude tests/ --branches

t: test

c: test_coverage

b: test_branches

tcb: t c b

spe:
	g++ -o unit_tests $(SRC_TESTS) $(TEST_FILES) --coverage -lcriterion $(INCLUDE)