/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:40:15 by jponieck          #+#    #+#             */
/*   Updated: 2024/04/09 22:42:11 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	pick_nearest(t_intarr *ia, int s, int s2)
{
	int	s_dist;
	int	s2_dist;

	if (s <= ia->len - s)
		s_dist = s;
	else
		s_dist = ia->len - s;
	if (s2 <= ia->len - s2)
		s2_dist = s2;
	else
		s2_dist = ia->len - s2;
	if (s_dist <= s2_dist)
		return (s);
	else
	{
		ia->next_n = ia->ints[s];
		return (s2);
	}
}

int	find_nearest_index(t_intarr *ia, int s, int s2, int i)
{
	i = 0;
	if (ia->next_n != -1)
	{
		while (ia->ints[i] != ia->next_n)
			i++;
		ia->next_n = -1;
		return (i);
	}
	while (i < ia->len)
	{
		if (ia->ints[i] < ia->ints[s])
			s = i;
		i++;
	}
	i = 0;
	if (s == 0)
		s2++;
	while (i < ia->len)
	{
		if (ia->ints[i] < ia->ints[s2] && ia->ints[i] > ia->ints[s])
			s2 = i;
		i++;
	}
	return (pick_nearest(ia, s, s2));
}

void	move_nearest(t_intarr *ia)
{
	int	s;

	s = find_nearest_index(ia, 0, 0, 0);
	if (s <= ia->len / 2)
	{
		while (s != 0)
		{
			rotate(ia);
			s--;
		}
	}
	else
	{
		while (s != ia->len)
		{
			rrotate(ia);
			s++;
		}
	}
}

void	move_from_a(t_intarr *ia, t_intarr *ib)
{
	while (is_sorted(ia) == 0)
	{
		if (swap_will_sort(ia) == 1)
		{
			swap(ia, ib);
			continue ;
		}
		if (is_sorted(ib) == 0)
			swap(ib, ia);
		move_nearest(ia);
		if (swap_will_sort(ia) == 1)
			swap(ia, ib);
		if (is_sorted(ia) == 0)
			push(ia, ib);
	}
}

void	move_from_b(t_intarr *ib, t_intarr *ia)
{
	if (is_sorted(ia) == 0)
		swap(ia, ib);
	if (is_sorted(ib) == 0)
		swap(ib, ia);
	while (ib->len > 0)
	{
		push(ib, ia);
	}
	if (is_sorted(ia) == 0)
		swap(ia, ib);
}
