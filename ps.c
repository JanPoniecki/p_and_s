/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:47:07 by jponieck          #+#    #+#             */
/*   Updated: 2024/04/09 21:16:15 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	iaa.args = argc;
	iab.ints = ft_calloc(argc - 1, sizeof(int));
	iab.len = 0;
	iab.sorting = -1;
	fill_up_array(&iaa, argv);
	simplify_array(&iaa);
	print_arrays(&iaa, &iab, iaa.args);
	move_from_a(&iaa, &iab);
	move_from_b(&iab, &iaa);
	ft_printf("%s\n", iaa.moves);
	free(iaa.ints);
	free(iaa.moves);
}
