/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a4.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:49:35 by jponieck          #+#    #+#             */
/*   Updated: 2024/04/17 23:27:24 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	absolute(int x)
{
	if (x >= 0)
		return (x);
	else
		return (-x);
}

void	set_direction(t_node *cheapest, int way_a, int way_b)
{
	if (way_a >= 0)
		cheapest->ra_dir = 1;
	else
		cheapest->ra_dir = -1;
	if (way_b >= 0)
		cheapest->rb_dir = 1;
	else
		cheapest->rb_dir = -1;
}

void	find_b_buddy(t_intarr *ia, t_intarr *ib, t_node *cheapest, int a_index)
{
	int	i;
	int	way_b;
	int	way_a;

	i = 0;
	while(ib->ints[i] != ia->ints[a_index] - 1)
		i++;
	if (i <= ib->len - i)
		way_b = i;
	else
		way_b = -(ib->len - i);
	if (a_index <= ia->len - a_index)
		way_a = a_index;
	else
		way_a = -(ia->len - a_index);
	if (absolute(way_a) + absolute(way_b) < cheapest->rbs + cheapest->ras)
	{
		cheapest->b_index = i;
		cheapest->ras = absolute(way_a);
		cheapest->rbs = absolute(way_b);
		set_direction(cheapest, way_a, way_b);
	}
}

void	sort_4(t_intarr *ia, t_intarr *ib, int i, t_node *cpst)
{
	cpst->b_index = 2147483647;
	cpst->rbs = 2147483647 / 2;
	cpst->ras = 2147483647 / 2;
	while (i < ia->len)
	{
		if (is_in_stack(ia, ia->ints[i] - 1) == 0 && ia->ints[i] != 10)
			find_b_buddy(ia, ib, cpst, i);
		i++;
	}
	ft_printf("chosen b is %d, ras %d, rbs %d, radir %d, rbdir %d\n", cpst->b_index, cpst->ras, cpst->rbs, cpst->ra_dir, cpst->rb_dir);
	meet_buddies(ia, ib, cpst);
	print_arrays(ia, ib, ia->len + ib->len + 1);
	exit (0);
}

void	al_4(t_intarr *ia, t_intarr *ib, char **argv)
{
	t_node	cheapest;

	ia->alg_id = 4;
	ft_bzero(ia->moves, ft_strlen(ia->moves));
	fill_up_array(ia, argv);
	simplify_array(ia);
	while (ia->len > 3)
		push(ia, ib);
	print_arrays(ia, ib, ia->len + ib->len + 1);
	while (ib->len > 0)
		sort_4(ia, ib, 0, &cheapest);
}