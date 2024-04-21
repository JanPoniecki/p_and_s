/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:47:07 by jponieck          #+#    #+#             */
/*   Updated: 2024/04/21 12:21:48 by jponieck         ###   ########.fr       */
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

	print_args(argv, argc);
	iaa.ints = ft_calloc(argc, sizeof(int));
	iaa.len = argc -1;
	iaa.sorting = 1;
	iaa.args = argc;
	iaa.max = argc - 1;
	iab.ints = ft_calloc(argc - 1, sizeof(int));
	iab.len = 1;
	ft_bzero(iab.ints, (argc - 1) * 4);
	// ft_memset(&(iab.ints[0]), 111, (argc - 1) * 4);
	iab.ints[0] = 0;
	iab.sorting = -1;
	check_args(argv, &iaa, &iab);
	fill_up_array(&iaa, argv);
	simplify_array(&iaa);
	if (argc <= 4)
		al_3(&iaa, &iab);
	else
		al_4(&iaa, &iab, argv);
	print_arrays(&iaa, &iab, iaa.len + iab.len + 1);
	end_program(NULL, &iaa, &iab);
}
