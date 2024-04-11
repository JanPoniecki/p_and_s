/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 22:56:51 by jponieck          #+#    #+#             */
/*   Updated: 2024/04/11 21:16:08 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	al_1(t_intarr *ia, t_intarr *ib, char **argv)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	ia->alg_id = 1;
	ft_bzero(ia->moves, ft_strlen(ia->moves));
	fill_up_array(ia, argv);
	simplify_array(ia);
	move_from_a(ia, ib);
	move_from_b(ib, ia);
	while (ia->moves[i])
	{
		if (ia->moves[i] == '\n')
			n++;
		i++;
	}
	return (n);
}

int	al_2(t_intarr *ia, t_intarr *ib, char **argv)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	ia->alg_id = 2;
	ia->moves_count = 0;
	ft_bzero(ia->moves, ft_strlen(ia->moves));
	fill_up_array(ia, argv);
	simplify_array(ia);
	print_arrays(ia, ib, ia->args);
	move_from_a(ia, ib);
	move_from_b(ib, ia);
	while (ia->moves[i])
	{
		if (ia->moves[i] == '\n')
			n++;
		i++;
	}
	return (n);
}

void	al_3(t_intarr *ia, t_intarr *ib, char **argv)
{
	ia->alg_id = 3;
	ft_bzero(ia->moves, ft_strlen(ia->moves));
	fill_up_array(ia, argv);
	simplify_array(ia);
	if (ia->ints[0] == 10 && ia->ints[1] == 12)
		ft_strlcpy(ia->moves, "rra\nsa\n", 8);
	if (ia->ints[0] == 11 && ia->ints[1] == 10)
		ft_strlcpy(ia->moves, "sa\n", 4);
	if (ia->ints[0] == 11 && ia->ints[1] == 12)
		ft_strlcpy(ia->moves, "rra\n", 5);
	if (ia->ints[0] == 12 && ia->ints[1] == 11)
		ft_strlcpy(ia->moves, "ra\nsa\n", 7);
	if (ia->ints[0] == 12 && ia->ints[1] == 10)
		ft_strlcpy(ia->moves, "ra\n", 4);
	end_program(NULL, ia, ib);
}
