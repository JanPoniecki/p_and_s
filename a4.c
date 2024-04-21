/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a4.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:49:35 by jponieck          #+#    #+#             */
/*   Updated: 2024/04/21 19:59:33 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

// used
void	init_tch(t_node *tch)
{
	tch->rbs = 0;
	tch->ras = 0;
	tch->rrbs = 0;
	tch->rras = 0;
	tch->rrs = 0;
	tch->rrrs = 0;
	tch->sum = 0;
}

// used
int	find_max(t_intarr *ib)
{
	int	i;
	int	m;

	i = 0;
	m = 0;
	while (i < ib->len)
	{
		if (ib->ints[i] > ib->ints[m])
			m = i;
		i++;
	}
	return (m);
}

// used
int	search_closest_b(t_intarr *ia, t_intarr *ib, t_node *tch, int a)
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
void	sum_rs(t_node *tch)
{
	if (tch->ras >= tch->rbs)
		tch->rrs = tch->rbs;
	else
		tch->rrs = tch->ras;
	if (tch->rras >= tch->rrbs)
		tch->rrrs = tch->rrbs;
	else
		tch->rrrs = tch->rras;
	tch->ras -= tch->rrs;
	tch->rbs -= tch->rrs;
	tch->rras -= tch->rrrs;
	tch->rrbs -= tch->rrrs;
	tch->sum = tch->ras + tch->rbs + tch->rras + tch->rrbs + tch->rrs + tch->rrrs;
}

// used
void	cpy_tch_2_ch(t_node *tch, t_node *ch)
{
	ch->ras = tch->ras;
	ch->rbs = tch->rbs;
	ch->rras = tch->rras;
	ch->rrbs = tch->rrbs;
	ch->rrs = tch->rrs;
	ch->rrrs = tch->rrrs;
	ch->sum = tch->sum;
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
	j = search_closest_b(ia, ib, &tch, ia->ints[i]);
	if (j <= ib->len - j)
		tch.rbs = j;
	else
		tch.rrbs = ib->len - j;
	sum_rs(&tch);
	if (tch.sum < ch->sum)
		cpy_tch_2_ch(&tch, ch);
}

// used
void	make_moves(t_node *ch, t_intarr *ia, t_intarr *ib)
{
	while (ch->ras > 0)
		ch->ras -= rotate(ia, 0);
	while (ch->rbs > 0)
		ch->rbs -= rotate(ib, 0);
	while (ch->rrs > 0)
	{
		ch->rrs -= rotate(ia, 1);
		rotate(ib, 1);
	}
	while (ch->rras > 0)
		ch->rras -= rrotate(ia, 0);
	while (ch->rrbs > 0)
		ch->rrbs -= rrotate(ib, 0);
	while (ch->rrrs > 0)
	{
		ch->rrrs -= rrotate(ia, 1);
		rrotate(ib, 1);
	}
	push(ia, ib);
}

// used
void	move_2_b(t_intarr *ia, t_intarr *ib, t_node *ch, int i)
{
	ch->sum = 2147483647;
	while (i < ia->len)
	{
		find_a_buddy(ia, ib, ch, i);
		i++;
	}
	make_moves(ch, ia, ib);
}

// used
void	move_2_a(t_intarr *ia, t_intarr *ib)
{
	if (ib->ints[0] > ia->ints[ia->len - 1] || ia->ints[ia->len - 1] == ia->max)
		push(ib, ia);
	else
		rrotate(ia, 0);
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
void	al_4(t_intarr *ia, t_intarr *ib, char **argv)
{
	t_node	cheapest;
	int		max_a;

	while (ib->len < 2)
			push(ia, ib);
	if (ib->ints[0] < ib->ints[1])
		swap(ib, ia);
	while (ia->len > 3)
		move_2_b(ia, ib, &cheapest, 0);
	al_3(ia, ib);
	find_min(ib, 0);
	if (ia->ints[ia->len - 1] == ia->max)
		rrotate(ia, 0);
	while (ib->len > 0)
		move_2_a(ia, ib);
}

// used
void	al_3(t_intarr *ia, t_intarr *ib)
{
	if (ia->len == 1)
		return;
	if (ia->len == 2)
	{
		if (ia->ints[0] > ia->ints[1])
			swap(ia, ib);
		return;
	}
	if (ia->ints[0] < ia->ints[2] && ia->ints[2] < ia->ints[1])
	{
		rrotate(ia, 0);
		swap(ia, ib);
	}
	if (ia->ints[0] < ia->ints[2] && ia->ints[1] < ia->ints[0])
		swap(ia, ib);
	if (ia->ints[0] > ia->ints[2] && ia->ints[1] > ia->ints[0])
		rrotate(ia, 0);
	if (ia->ints[0] > ia->ints[1] && ia->ints[1] > ia->ints[2])
	{
		rotate(ia, 0);
		swap(ia, ib);
	}
	if (ia->ints[0] > ia->ints[2] && ia->ints[2] > ia->ints[1])
		rotate(ia, 0);
}
