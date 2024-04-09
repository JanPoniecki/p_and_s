/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:30:55 by jponieck          #+#    #+#             */
/*   Updated: 2024/04/09 20:51:05 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	append_move(t_intarr *ia, char *move)
{
	int	i;

	i = 0;
	while (ia->moves[i])
		i++;
	while (*move)
	{
		ia->moves[i] = *move;
		i++;
		move++;
	}
	ia->moves[i] = '\n';
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

	i = ia->len + 1;
	while (i > 0)
	{
		ia->ints[i] = ia->ints[i - 1];
		i--;
	}
}
