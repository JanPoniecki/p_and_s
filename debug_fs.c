/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_fs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:35:12 by jponieck          #+#    #+#             */
/*   Updated: 2024/04/11 20:03:11 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	print_args(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
		ft_printf("%s ", argv[i++]);
	ft_printf("\n");
}

void	print_arrays(t_intarr *ia, t_intarr *ib, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		ft_printf("%d\t%d\n", ia->ints[i], ib->ints[i]);
		i++;
	}
	ft_printf("----\n");
}

void print_flat(t_intarr *ia, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 1)
		ft_printf("%d ", ia->ints[i++]);
	ft_printf("\n");
}

// void	print_result()
