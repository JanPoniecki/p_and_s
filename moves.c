/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:31:13 by jponieck          #+#    #+#             */
/*   Updated: 2024/04/17 23:34:48 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	rotate(t_intarr *ia)
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
	if (ia->sorting == 1)
		append_move(ia, "ra");
	else
		append_move(ia, "rb");
}

void	rrotate(t_intarr *ia)
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
	if (ia->sorting == 1)
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
}

void	swap(t_intarr *ia, t_intarr *ib)
{
	int	temp;

	temp = ia->ints[0];
	ia->ints[0] = ia->ints[1];
	ia->ints[1] = temp;
	if (ia->sorting == 1)
		append_move(ia, "sa");
	else
		append_move(ib, "sb");
}

void	push(t_intarr *from, t_intarr *to)
{
	shift_down(to);
	to->len++;
	to->ints[0] = from->ints[0];
	shift_up(from);
	from->len--;
	if (from->sorting == 1)
		append_move(from, "pb");
	else
		append_move(to, "pa");
}
