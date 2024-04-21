/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:47:07 by jponieck          #+#    #+#             */
/*   Updated: 2024/04/21 20:02:18 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

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
	// iab.ints[0] = 0;
	iab.sorting = -1;
	check_args(argv, &iaa, &iab);
	fill_up_array(&iaa, argv);
	simplify_array(&iaa);
	// print_arrays(&iaa, &iab, argc);
	if (argc <= 4)
		al_3(&iaa, &iab);
	else
		al_4(&iaa, &iab, argv);
	finish_me(&iaa);
	// print_arrays(&iaa, &iab, argc);
	end_program(NULL, &iaa, &iab);
}
