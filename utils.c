/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:30:55 by jponieck          #+#    #+#             */
/*   Updated: 2024/04/21 21:48:16 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

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

void	shift_up(t_intarr *ia)
{
	int	i;

	i = 1;
	while (i < ia->len)
	{
		ia->ints[i - 1] = ia->ints[i];
		i++;
	}
	ia->ints[i - 1] = 0;
}

void	shift_down(t_intarr *ia)
{
	int	i;

	i = ia->len;
	while (i > 0)
	{
		ia->ints[i] = ia->ints[i - 1];
		i--;
	}
}
