/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a4.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:49:35 by jponieck          #+#    #+#             */
/*   Updated: 2024/04/21 12:18:47 by jponieck         ###   ########.fr       */
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

void	finish_me(t_intarr *ia)
{
	int	i;

	i = 0;
	while(ia->ints[i] != 10)
		i++;
	if (i <= ia->len - i)
	{
		while(ia->ints[0] != 10)
			rotate(ia, 0);
	}
	else
	{
		while(ia->ints[0] != 10)
			rrotate(ia, 0);
	}
}

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
	return (c);
}

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

void	move_2_b(t_intarr *ia, t_intarr *ib, t_node *ch, int i)
{
	ch->sum = 2147483647;
	while (i < ia->len)
	{
		find_a_buddy(ia, ib, ch, i);
		i++;
	}
	print_arrays(ia, ib, ia->len + ib->len + 1);
	print_cheapest(ch);
	make_moves(ch, ia, ib);
	print_arrays(ia, ib, ia->len + ib->len + 1);
	ft_printf("--------------------------------------------------------------\n");
	// print_cheapest(ch);
	// exit(0);
}

void	move_2_a(t_intarr *ia, t_intarr *ib)
{
	if (ib->ints[0] > ia->ints[ia->len - 1] || ia->ints[ia->len - 1] == ia->max)
		push(ib, ia);
	else
		rrotate(ia, 0);
	print_arrays(ia, ib, ia->len + ib->len + 1);
}

void	find_zero(t_intarr *ib)
{
	int	i;

	i = 0;
	while (ib->ints[i] != 0)
		i++;
	if (i <= ib->len - i)
	{
		while (ib->ints[ib->len - 1] != 0)
			rotate(ib, 0);
	}
	else
	{
		while (ib->ints[ib->len - 1] != 0)
			rrotate(ib, 0);
	}
}

void	al_4(t_intarr *ia, t_intarr *ib, char **argv)
{
	t_node	cheapest;
	int		max_a;

	// if (ia->ints[0] > ia->ints[1])
	// {
	// 	ib->min = ia->ints[1];
	// 	ib->max = ia->ints[0];
	// }
	// else
	// {
	// 	ib->min = ia->ints[0];
	// 	ib->max = ia->ints[1];
	// }
	while (ib->len < 3)
		push(ia, ib);
	if (ib->ints[0] < ib->ints[1])
		swap(ib, ia);
	while (ia->len > 3)
		move_2_b(ia, ib, &cheapest, 0);
	al_3(ia, ib);
	find_zero(ib);
	if (ia->ints[ia->len - 1] == ia->max)
		rrotate(ia, 0);
	while (ib->len > 1)
		move_2_a(ia, ib);
	print_arrays(ia, ib, ia->len + ib->len + 1);
}

void	al_3(t_intarr *ia, t_intarr *ib)
{
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
