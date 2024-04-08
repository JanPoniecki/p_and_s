#include "ps.h"

void	append_move(t_intarr *ia, char *move)
{
	int	i;

	i = 0;
	while (ia->moves[i])
		i++;
	while (*move)
	{
		ia->moves[i] = *move;
		i++;
		move++;
	}
	ia->moves[i] = '\n';
}