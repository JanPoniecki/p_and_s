/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a4.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:49:35 by jponieck          #+#    #+#             */
/*   Updated: 2024/04/21 22:19:21 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	search_closest_b(t_intarr *ib, int a)
{
	int	j;
	int	number;
	int	c;

	j = 0;
	number = 0;
	c = 0;
	while (ib->ints[c] != 0)
		c++;
	while (j < ib->len)
	{
		if (a > ib->ints[j] && ib->ints[j] > number)
		{
			c = j;
			number = ib->ints[j];
		}
		j++;
	}
	if (number == 0)
		return (find_max(ib));
	return (c);
}

// used
void	find_a_buddy(t_intarr *ia, t_intarr *ib, t_node *ch, int i)
{
	t_node	tch;
	int		j;

	init_tch(&tch);
	if (i <= ia->len - i)
		tch.ras = i;
	else
		tch.rras = ia->len - i;
	j = search_closest_b(ib, ia->ints[i]);
	if (j <= ib->len - j)
		tch.rbs = j;
	else
		tch.rrbs = ib->len - j;
	sum_rs(&tch);
	if (tch.sum < ch->sum)
		cpy_tch_2_ch(&tch, ch);
}

// used
void	find_min(t_intarr *ib, int i)
{
	int	min;
	int	nr;

	min = 0;
	nr = ib->ints[0];
	while (i < ib->len)
	{
		if (ib->ints[i] < ib->ints[min])
		{
			min = i;
			nr = ib->ints[min];
		}
		i++;
	}
	if (min <= ib->len - i)
	{
		while (ib->ints[ib->len - 1] != nr)
			rotate(ib, 0);
	}
	else
	{
		while (ib->ints[ib->len - 1] != nr)
			rrotate(ib, 0);
	}
}

// used
void	al_4(t_intarr *ia, t_intarr *ib)
{
	t_node	cheapest;

	while (ib->len < 2)
		push(ia, ib);
	if (ib->ints[0] < ib->ints[1])
		swap(ib);
	while (ia->len > 3)
		move_2_b(ia, ib, &cheapest, 0);
	al_3(ia);
	find_min(ib, 0);
	if (ia->ints[ia->len - 1] == ia->max)
		rrotate(ia, 0);
	while (ib->len > 0)
		move_2_a(ia, ib);
}

// used
void	al_3(t_intarr *ia)
{
	if (ia->len == 1)
		return ;
	if (ia->len == 2)
	{
		if (ia->ints[0] > ia->ints[1])
			swap(ia);
		return ;
	}
	if (ia->ints[0] < ia->ints[2] && ia->ints[2] < ia->ints[1])
	{
		rrotate(ia, 0);
		swap(ia);
	}
	if (ia->ints[0] < ia->ints[2] && ia->ints[1] < ia->ints[0])
		swap(ia);
	if (ia->ints[0] > ia->ints[2] && ia->ints[1] > ia->ints[0])
		rrotate(ia, 0);
	if (ia->ints[0] > ia->ints[1] && ia->ints[1] > ia->ints[2])
	{
		rotate(ia, 0);
		swap(ia);
	}
	if (ia->ints[0] > ia->ints[2] && ia->ints[2] > ia->ints[1])
		rotate(ia, 0);
}
