/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:31:13 by jponieck          #+#    #+#             */
/*   Updated: 2024/04/21 22:10:41 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	rotate(t_intarr *ia, int dbl)
{
	int	temp;
	int	i;

	i = 0;
	temp = ia->ints[0];
	while (i < ia->len)
	{
		ia->ints[i] = ia->ints[i + 1];
		i++;
	}
	ia->ints[i - 1] = temp;
	if (dbl == 0)
	{
		if (ia->sorting == 1)
			ft_printf("ra\n");
		else
			ft_printf("rb\n");
	}
	else if (ia->sorting == 1)
		ft_printf("rr\n");
	return (1);
}

int	rrotate(t_intarr *ia, int dbl)
{
	int	temp;
	int	i;

	i = ia->len - 1;
	temp = ia->ints[i];
	while (i > 0)
	{
		ia->ints[i] = ia->ints[i - 1];
		i--;
	}
	ia->ints[0] = temp;
	if (dbl == 0)
	{
		if (ia->sorting == 1)
			ft_printf("rra\n");
		else
			ft_printf("rrb\n");
	}
	else if (ia->sorting == 1)
		ft_printf("rrr\n");
	return (1);
}

void	swap(t_intarr *ia)
{
	int	temp;

	temp = ia->ints[0];
	ia->ints[0] = ia->ints[1];
	ia->ints[1] = temp;
	if (ia->sorting == 1)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}

void	push(t_intarr *from, t_intarr *to)
{
	shift_down(to);
	to->len++;
	to->ints[0] = from->ints[0];
	shift_up(from);
	from->len--;
	if (from->sorting == 1)
		ft_printf("pb\n");
	else
		ft_printf("pa\n");
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
