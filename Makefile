_END=\033[0m
_BOLD=\033[1m
_UNDER=\033[4m
_REV=\033[7m

_DEFAULT=\033[39m
_RED=\033[31m
_GREEN=\033[32m
_YELLOW=\033[33m
_BLUE=\033[34m
_MAGENTA=\033[35m
_CYAN=\033[36m
_LIGHTGRAY=\033[37m
_DARKGRAY=\033[90m
_LIGHTRED=\033[91m
_LIGHTGREEN=\033[92m
_LIGHTYELLOW=\033[93m
_LIGHTBLUE=\033[94m
_LIGHTMAGENTA=\033[95m
_LIGHTCYAN=\033[96m
_WHITE=\033[97m

NAME = containers

CC = clang++
MAKE = make

CFLAGS = -Wall -Wextra -Werror
# CFLAGS += -O3 -fno-builtin
# CFLAGS += -g
# CFLAGS += -fsanitize=address

CT_SRC = \
	./main.cpp

CT_LIB = \
	./lib/vector.hpp
	./lib/iterators/iterator_traits.hpp
	./lib/iterators/random_access_iterator.hpp
	./lib/utils/is_integral.hpp

SRCS = \
	$(CT_SRC) \

OBJS = $(SRCS:%.cpp=%.o)

%.o: %.cpp Makefile
	@printf "[ $(_GREEN)$(_BOLD)compiling$(_END) ] $(_BLUE)$(_BOLD)$<$(_END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@printf "[ $(_YELLOW)$(_BOLD)building$(_END) ] $(_BLUE)$(_BOLD)$(NAME)$(_END)\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@printf "[ $(_MAGENTA)$(_BOLD)done$(_END) ]\n"

clean:
	@printf "[ $(_RED)$(_BOLD)removing$(_END) ] $(_BLUE)$(_BOLD)objs$(_END)\n"
	@$(RM) $(OBJS)

fclean: clean
	@printf "[ $(_RED)$(_BOLD)removing$(_END) ] $(_BLUE)$(_BOLD)$(NAME)$(_END)\n"
	@$(RM) $(NAME)

re: fclean
	@$(MAKE) all

run: all
	@printf "[ $(_MAGENTA)$(_BOLD)running$(_END) ] $(_BLUE)$(_BOLD)$(NAME)...$(_END)\n"
	@./$(NAME)

norm:
	@norminette

.PHONY: all clean fclean re run norm