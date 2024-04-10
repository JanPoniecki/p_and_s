/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:30:55 by jponieck          #+#    #+#             */
/*   Updated: 2024/04/10 22:50:27 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

char	*re_calloc(char *src, int size)
{
	char	*new;
	int		src_len;

	src_len = ft_strlen(src);
	new = ft_calloc((src_len + size), sizeof(char));
	ft_strlcpy(new, src, src_len + size);
	free(src);
	return (new);
}

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
	ia->moves_count++;
	if (ia->moves_count * 4 > (1000 - 4))
	{
		ia->moves = re_calloc(ia->moves, 1000);
		ia->moves = 0;
	}
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
