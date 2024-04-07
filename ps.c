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

int	main(int argc, char **argv)
{
	t_intarr iaa;
	t_intarr iab;

	iaa.ints = ft_calloc(argc - 1, sizeof(int));
	iaa.len = argc -1;
	iaa.sorting = 1;
	iab.ints = ft_calloc(argc - 1, sizeof(int));
	iab.len = 0;
	iab.sorting = -1;
	fill_up_array(&iaa, argv);
	simplify_array(&iaa);
	ft_printf("sorted %d\n", is_sorted(&iaa));
	free(iaa.ints);
}