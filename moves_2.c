/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:52:47 by jponieck          #+#    #+#             */
/*   Updated: 2024/04/21 22:08:10 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

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

void	move_2_a(t_intarr *ia, t_intarr *ib)
{
	if (ib->ints[0] > ia->ints[ia->len - 1] || ia->ints[ia->len - 1] == ia->max)
		push(ib, ia);
	else
		rrotate(ia, 0);
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
	tch->sum = tch->ras + tch->rbs + tch->rras + \
		tch->rrbs + tch->rrs + tch->rrrs;
}
