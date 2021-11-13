NAME = containers

CC = clang++
MAKE = make --no-print-directory

CPPFLAGS = -Wall -Wextra -Werror -std=c++98
# CPPFLAGS += -g
CPPFLAGS += -O3 -fno-builtin
# CPPFLAGS += -fsanitize=address

INCLUDE = ./includes

HEADERS = \
	$(INCLUDE)/map.hpp \
	$(INCLUDE)/stack.hpp \
	$(INCLUDE)/vector.hpp \
	$(INCLUDE)/iterators/random_access_iterator.hpp \
	$(INCLUDE)/iterators/reverse_iterator.hpp \
	$(INCLUDE)/iterators/rb_iterator.hpp \
	$(INCLUDE)/iterators/iterator_traits.hpp \
	$(INCLUDE)/utils/is_integral.hpp \
	$(INCLUDE)/utils/compare.hpp \
	$(INCLUDE)/utils/rb_tree.hpp \


SRCS = \
	./main.cpp \
	./tests/stack.cpp \
	./tests/vector.cpp \
	./tests/map.cpp \

FT_OBJS = $(SRCS:%.cpp=%_ft.o)
STL_OBJS = $(SRCS:%.cpp=%_stl.o)

%_ft.o: %.cpp Makefile $(HEADERS)
	$(CC) $(CPPFLAGS) -I$(INCLUDE) -c $< -o $@

%_stl.o: %.cpp Makefile $(HEADERS)
	$(CC) $(CPPFLAGS) -DSTL -I$(INCLUDE) -c $< -o $@

all: ft_$(NAME) stl_$(NAME)

ft_$(NAME): $(FT_OBJS)
	$(CC) $(CPPFLAGS) -o ft_$(NAME) $(FT_OBJS)

stl_$(NAME): $(STL_OBJS)
	$(CC) $(CPPFLAGS) -o stl_$(NAME) $(STL_OBJS)

clean:
	$(RM) $(FT_OBJS)
	$(RM) $(STL_OBJS)

fclean: clean
	$(RM) ft_$(NAME)
	$(RM) stl_$(NAME)
	$(RM) *.out

re: fclean
	$(MAKE) all

test: all
	$(MAKE) -j _test_all;

_test_stl:
	./stl_$(NAME) > stl_test.out

_test_ft:
	./ft_$(NAME) > ft_test.out

_test_all:  _test_stl _test_ft
	diff stl_test.out ft_test.out

.PHONY: all clean fclean test bench