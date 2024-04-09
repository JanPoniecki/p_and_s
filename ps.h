#ifndef PS_H
# define PS_H
#endif

#include "libft/libft.h"

typedef struct	s_intarr
{
	int		len;
	int		*ints;
	int		sorting;
	char	*moves;
	char	col;
	int		next_n;
}	t_intarr;

void	decrease(int nr, int *arr, int len);
void	fill_up_array(t_intarr *ia, char **src);
int		next_one(int *iarr, int len);
void	simplify_array(t_intarr *ia);
void	rotate(t_intarr *ia);
void	rrotate(t_intarr *ia);
void	append_move(t_intarr *ia, char *move);
void	push(t_intarr *from, t_intarr *to);
void	swap(t_intarr *ia, t_intarr *ib);
