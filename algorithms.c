/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 22:56:51 by jponieck          #+#    #+#             */
/*   Updated: 2024/04/18 22:22:55 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	al_1(t_intarr *ia, t_intarr *ib, char **argv)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	ia->alg_id = 1;
	ft_bzero(ia->moves, ft_strlen(ia->moves));
	fill_up_array(ia, argv);
	simplify_array(ia);
	move_from_a(ia, ib);
	move_from_b(ib, ia);
	while (ia->moves[i])
	{
		if (ia->moves[i] == '\n')
			n++;
		i++;
	}
	return (n);
}

int	al_2(t_intarr *ia, t_intarr *ib, char **argv)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	ia->alg_id = 2;
	ia->moves_count = 0;
	ft_bzero(ia->moves, ft_strlen(ia->moves));
	fill_up_array(ia, argv);
	simplify_array(ia);
	print_arrays(ia, ib, ia->args);
	move_from_a(ia, ib);
	move_from_b(ib, ia);
	while (ia->moves[i])
	{
		if (ia->moves[i] == '\n')
			n++;
		i++;
	}
	return (n);
}

void	al_3(t_intarr *ia, t_intarr *ib, int max_a)
{
	if (ia->ints[0] == max_a - 2 && ia->ints[1] == max_a)
	{
		rrotate(ia, 0);
		swap(ia, ib);
	}
	if (ia->ints[0] == max_a - 1 && ia->ints[1] == max_a - 2)
		swap(ia, ib);
	if (ia->ints[0] == max_a - 1 && ia->ints[1] == max_a)
		rrotate(ia, 0);
	if (ia->ints[0] == max_a && ia->ints[1] == max_a - 1)
	{
		rotate(ia, 0);
		swap(ia, ib);
	}
	if (ia->ints[0] == max_a && ia->ints[1] == max_a - 2)
		rotate(ia, 0);
}
