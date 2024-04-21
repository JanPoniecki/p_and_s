FLAGS = -Wall -Wextra -Werror
SRC_FILES = prepare.c ps.c moves.c utils.c debug_fs.c errors.c a4.c

all:
	cc -g $(SRC_FILES) -L./libft -lft -o push_swap
flags:
	cc $(FLAGS) -g $(SRC_FILES) -L./libft -lft
