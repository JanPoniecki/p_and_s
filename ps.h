#ifndef PS_H
# define PS_H
#endif

#include "libft/libft.h"

typedef struct	s_intarr
{
	int	len;
	int	*ints;
	int	sorting;
}	t_intarr;

void	decrease(int nr, int *arr, int len);
void	fill_up_array(t_intarr *ia, char **src);
int		next_one(int *iarr, int len);
void	simplify_array(t_intarr *ia);