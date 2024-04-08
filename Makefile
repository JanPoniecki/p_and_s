FLAGS = -Wall -Wextra -Werror
SRC_FILES = prepare.c ps.c moves.c utils.c

all:
	cc -g $(SRC_FILES) -L./libft -lft
flags:
	cc $(FLAGS) -g $(SRC_FILES) -L./libft -lft
