FLAGS = -Wall -Wextra -Werror
SRC_FILES = prepare.c ps.c moves.c utils.c debug_fs.c moves_2.c errors.c algorithms.c a4.c

all:
	cc -g $(SRC_FILES) -L./libft -lft
flags:
	cc $(FLAGS) -g $(SRC_FILES) -L./libft -lft
