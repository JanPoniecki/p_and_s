/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:40:15 by jponieck          #+#    #+#             */
/*   Updated: 2024/04/19 20:19:52 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	perform_dbl_mvs(t_intarr *ia, t_intarr *ib, t_node *cpst)
{
	if (cpst->rb_dir == cpst->ra_dir)
	{
		if (cpst->rb_dir == 1)
		{
			while (cpst->rbs != 0 && cpst->ras != 0)
			{
				rotate(ia, 1);
				rotate(ib, 1);
				cpst->ras--;
				cpst->rbs--;
			}
		}
		else
		{
			while (cpst->rbs != 0 && cpst->ras != 0)
			{
				rrotate(ia, 1);
				rrotate(ib, 1);
				cpst->ras--;
				cpst->rbs--;
			}
		}
	}
}

void	meet_buddies(t_intarr *ia, t_intarr *ib, t_node *cpst)
{
	perform_dbl_mvs(ia, ib, cpst);
	while(cpst->rbs > 0)
	{
		if (cpst->rb_dir == 1)
			rotate(ib, 0);
		else
			rrotate(ib, 0);
		cpst->rbs--;
	}
	while(cpst->ras > 0)
	{
		if (cpst->ra_dir == 1)
			rotate(ia, 0);
		else
			rrotate(ia, 0);
		cpst->ras--;
	}
	push(ib, ia);
}

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

int	next_one_1(int *iarr, int len)
{
	int	i;
	int	min;

	i = 0;
	min = 0;
	while (i < len)
	{
		if (iarr[i] < iarr[min])
			min = i;
		i++;
	}
	return (iarr[min]);
}

void	move_nearest(t_intarr *ia)
{
	int	s;

	if (ia->alg_id == 2)
		ia->next_n = next_one_1(ia->ints, ia->len);
	s = find_nearest_index(ia, 0, 0, 0);
	if (s <= ia->len / 2)
	{
		while (s != 0)
		{
			rotate(ia, 0);
			s--;
		}
	}
	else
	{
		while (s != ia->len)
		{
			rrotate(ia, 0);
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
