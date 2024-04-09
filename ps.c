#include "ps.h"

int	is_sorted(t_intarr *ia)
{
	int	i;

	if (ia->sorting == 1)
	{
		i = 0;
		while (i < ia->len - 1)
		{
			if (ia->ints[i] + 1 != ia->ints[i + 1])
				return (0);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < ia->len)
		{
			if (ia->ints[i] < ia->ints[i + 1])
				return (0);
			i++;
		}
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
	{
		ia->next_n = ia->ints[s];
		return (s2);
	}
}

int	find_nearest_index(t_intarr *ia, int s, int s2)
{
	int	i;

	i = 0;
	if (ia->next_n != -1)
	{
		while (ia->ints[i] != ia->next_n)
			i++;
		ia->next_n = -1;
		return (i);
	}
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
	return (pick_nearest(ia, s, s2));
}

void	move_nearest(t_intarr *ia)
{
	int	s;

	s = find_nearest_index(ia, 0, 0);
	if (s <= ia->len/2)
	{
		while (s != 0)
		{
			rotate(ia);
			s--;
		}
	}
	else
	{
		while (s != ia->len)
		{
			rrotate(ia);
			s++;
		}
	}
}

void	print_args(char **argv, int argc)
{
	int i = 1;
	while (i < argc)
		ft_printf("%s ", argv[i++]);
	ft_printf("\n");
}

void	print_arrays(t_intarr *ia, t_intarr *ib, int argc)
{
	int i = 0;
	while (i < argc - 1)
	{
		ft_printf("%d\t%d\n", ia->ints[i], ib->ints[i]);
		i++;
	}
	ft_printf("----\n");
}

void	move_from_a(t_intarr *ia, t_intarr *ib, int argc)
{
	while (is_sorted(ia) == 0)
	{
		if (swap_will_sort(ia) == 1)
		{
			swap(ia, ib);
			continue ;
		}
		if (is_sorted(ib) == 0)
			swap(ib, ia);
		move_nearest(ia);
		if (is_sorted(ia) == 0)
			push(ia, ib);
		print_arrays(ia, ib, argc);
	}
}

void	move_from_b(t_intarr *ib, t_intarr *ia, int argc)
{
	if (is_sorted(ia) == 0)
		swap(ia, ib);
	if (is_sorted(ib) == 0)
		swap(ib, ia);
	while (ib->len > 0)
	{
		push(ib, ia);
		print_arrays(ia, ib, argc);
	}
	if (is_sorted(ia) == 0)
		swap(ia, ib);
}

int	main(int argc, char **argv)
{
	t_intarr	iaa;
	t_intarr	iab;

	system("clear");
	print_args(argv, argc);
	iaa.moves = ft_calloc(1000, sizeof(char));
	iaa.ints = ft_calloc(argc - 1, sizeof(int));
	iaa.len = argc -1;
	iaa.sorting = 1;
	iaa.next_n = -1;
	iab.ints = ft_calloc(argc - 1, sizeof(int));
	iab.len = 0;
	iab.sorting = -1;
	fill_up_array(&iaa, argv);
	simplify_array(&iaa);
	print_arrays(&iaa, &iab, argc);
	move_from_a(&iaa, &iab, argc);
	move_from_b(&iab, &iaa, argc);
	print_arrays(&iaa, &iab, argc);
	// move_nearest(&iaa);
	// print_arrays(&iaa, &iab);
	// push(&iaa, &iab);
	// print_arrays(&iaa, &iab);
	// swap(&iaa);
	// print_arrays(&iaa, &iab);
	ft_printf("%s\n", iaa.moves);
	free(iaa.ints);
	free(iaa.moves);
}
