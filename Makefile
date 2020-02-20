##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CXX        =    g++

MAIN_SRC    =    src/main.cpp			\

MAIN_OBJ    =    $(MAIN_SRC:.cpp=.o)	\

CXXFLAGS    =    -I./include -Wextra -g3 -W -Wall -pedantic

TARGET    =		hashcode		\

all: $(TARGET) ## Build the project

$(TARGET): build

build: $(OBJ) $(MAIN_OBJ) ## Compile the project
	@printf "\e[1;3;5;32m▀▄▀▄▀▄ Finished compiling sources ▄▀▄▀▄▀\e[0m\n"
	@$(CXX) $(CXXFLAGS) $(MAIN_OBJ) -o $(TARGET)
	@printf "[\e[1;34m-Link Main-\e[0m] % 43s\n" $(MAIN_OBJ) | tr ' ' '.'
	@printf "\e[1;3;5;32m▀▄▀▄▀▄ Link all object ▄▀▄▀▄▀\e[0m\n"

%.o : %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@printf "[\e[1;34m-Compiled-\e[0m] % 41s\n" $@ | tr ' ' '.'

clean: ## Clean the useless file
	@rm -f $(MAIN_OBJ)

fclean: clean ## Clean the project
	@rm -f $(TARGET)
	@printf "[\e[1;31m-RM-\e[0m] % 42s\n" $(TARGET) | tr ' ' '.'
	@printf "\e[1;3;5;32m▀▄▀▄▀▄ Finished RM ▄▀▄▀▄▀\e[0m\n"

re:    fclean all ## Clean then compile

valgrind: fclean all ## Launch valgrind
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

help: ## Help for the Makefile
	@cat $(MAKEFILE_LIST) | sed -En 's/^([a-zA-Z_-]+)\s*:.*##\s?(.*)/\1 "\2"/p' | xargs printf "\033[32m%-30s\033[0m %s\n"

.PHONY:	all build clean fclean re valgrind help