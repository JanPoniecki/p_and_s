/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:47:07 by jponieck          #+#    #+#             */
/*   Updated: 2024/04/21 22:18:33 by jponieck         ###   ########.fr       */
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

void	finish_me(t_intarr *ia)
{
	int	i;

	i = 0;
	while (ia->ints[i] != 1)
		i++;
	if (i <= ia->len - i)
	{
		while (ia->ints[0] != 1)
			rotate(ia, 0);
	}
	else
	{
		while (ia->ints[0] != 1)
			rrotate(ia, 0);
	}
}

int	main(int argc, char **argv)
{
	t_intarr	iaa;
	t_intarr	iab;

	iaa.ints = ft_calloc(argc, sizeof(int));
	iaa.len = argc -1;
	iaa.sorting = 1;
	iaa.args = argc;
	iaa.max = argc - 1;
	iab.ints = ft_calloc(argc - 1, sizeof(int));
	iab.len = 0;
	ft_bzero(iab.ints, (argc - 1) * 4);
	iab.sorting = -1;
	check_args(argv, &iaa, &iab);
	fill_up_array(&iaa, argv);
	simplify_array(&iaa);
	if (is_sorted(&iaa) == 0)
	{
		if (argc <= 4)
			al_3(&iaa);
		else
			al_4(&iaa, &iab);
		finish_me(&iaa);
	}
	end_program(NULL, &iaa, &iab);
}
