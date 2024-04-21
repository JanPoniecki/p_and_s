FLAGS = -Wall -Wextra -Werror
SRC_FILES = prepare.c ps.c moves.c utils.c debug_fs.c errors.c a4.c moves_2.c ft_atoi_long.c
# ARG := $(shell python3 rnd.py $(N))

all:
	cc -g $(SRC_FILES) -L./libft -lft -o push_swap

flags:
	cc $(FLAGS) -g $(SRC_FILES) -L./libft -lft

test:
	./push_swap $(ARG) | ./checker_linux $(ARG)