FLAGS = -Wall -Wextra -Werror
SRC_FILES = prepare.c ps.c

all:
	cc $(FLAGS) -g $(SRC_FILES) -L./libft -lft
