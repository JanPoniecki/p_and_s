#include "ps.h"

int	is_sorted(t_intarr *ia)
{
	int	i;

	i = ia->len - 1;
	while (i > 0)
	{
		if (ia->ints[i] - ia->sorting != ia->ints[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int	swap_will_sort(t_intarr *ia)
{
	int	temp;
	int	res;

	if (ia->len < 2)
		return (0);
	temp = ia->ints[0];
	ia->ints[0] = ia->ints[1];
	ia->ints[1] = temp;
	if (is_sorted(ia) == 0)
		res = 0;
	else
		res = 1;
	temp = ia->ints[0];
	ia->ints[0] = ia->ints[1];
	ia->ints[1] = temp;
	return (res);
}

int	pick_nearest(t_intarr *ia, int s, int s2)
{
	int	s_dist;
	int	s2_dist;

	if (s <= ia->len - s)
		s_dist = s;
	else
		s_dist = ia->len - s;
	if (s2 <= ia->len - s2)
		s2_dist = s2;
	else
		s2_dist = ia->len - s2;
	if (s_dist <= s2_dist)
		return (s);
	else
		return (s2);
}

int	find_nearest_index(t_intarr *ia, int s, int s2)
{
	int	i;

	i = 0;
	while (i < ia->len)
	{
		if (ia->ints[i] < ia->ints[s])
			s = i;
		i++;
	}
	i = 0;
	if (s == 0)
		s2++;
	while (i < ia->len)
	{
		if (ia->ints[i] < ia->ints[s2] && ia->ints[i] > ia->ints[s])
			s2 = i;
		i++;
	}
	ft_printf("s %d s2 %d\n", s, s2);
	return (pick_nearest(ia, s, s2));
}

void	move_nearest(t_intarr *ia, char *moves)
{
	int	s;

	s = find_nearest_index(ia, 0, 0);
	ft_printf("first one to move: %d\n", s);
}

int	main(int argc, char **argv)
{
	t_intarr	iaa;
	t_intarr	iab;
	char		*moves;

	moves = ft_calloc(1000, sizeof(char));
	iaa.ints = ft_calloc(argc - 1, sizeof(int));
	iaa.len = argc -1;
	iaa.sorting = 1;
	iab.ints = ft_calloc(argc - 1, sizeof(int));
	iab.len = 0;
	iab.sorting = -1;
	fill_up_array(&iaa, argv);
	simplify_array(&iaa);
	move_nearest(&iaa, moves);
	free(iaa.ints);
	free(moves);
}
