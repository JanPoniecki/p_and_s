#include "ps.h"

void	rotate(t_intarr *ia)
{
	int	temp;
	int	i;

	i = 0;
	temp = ia->ints[0];
	while (i < ia->len)
	{
		ia->ints[i] = ia->ints[i + 1];
		i++;
	}
	ia->ints[i - 1] = temp;
	if (ia->sorting == 1)
		append_move(ia, "ra");
	else
		append_move(ia, "rb");
}

void	rrotate(t_intarr *ia)
{
	int	temp;
	int	i;

	i = ia->len - 1;
	temp = ia->ints[i];
	while (i > 0)
	{
		ia->ints[i] = ia->ints[i - 1];
		i--;
	}
	ia->ints[0] = temp;
	if (ia->sorting == 1)
		append_move(ia, "rra");
	else
		append_move(ia, "rrb");
}
void	shift_up(t_intarr *ia)
{
	int	i;

	i = 1;
	while (i < ia->len)
	{
		ia->ints[i - 1] = ia->ints[i];
		i++;
	}
	ia->ints[i - 1] = 0;
}

void	shift_down(t_intarr *ia)
{
	int	i;

	i = ia->len + 1;
	while (i > 0)
	{
		ia->ints[i] = ia->ints[i - 1];
		i--;
	}
}

void	swap(t_intarr *ia, t_intarr *ib)
{
	int	temp;

	temp = ia->ints[0];
	ia->ints[0] = ia->ints[1];
	ia->ints[1] = temp;
	if (ia->sorting == 1)
		append_move(ia, "sa");
	else
		append_move(ib, "sb");
}

void	push(t_intarr *from, t_intarr *to)
{
	shift_down(to);
	to->len++;
	to->ints[0] = from->ints[0];
	shift_up(from);
	from->len--;
	if (from->sorting == 1)
		append_move(from, "pb");
	else
		append_move(to, "pa");
}