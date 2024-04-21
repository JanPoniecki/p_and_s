/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:55:31 by jponieck          #+#    #+#             */
/*   Updated: 2024/04/21 22:18:49 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include "libft/libft.h"

typedef struct s_intarr
{
	int		len;
	int		*ints;
	int		sorting;
	int		args;
	int		max;
}	t_intarr;

typedef struct s_node
{
	int	rbs;
	int	ras;
	int	rrbs;
	int	rras;
	int	rrs;
	int	rrrs;
	int	sum;
}	t_node;

void	decrease(int nr, int *arr, int len);
void	fill_up_array(t_intarr *ia, char **src);
int		next_one(int *iarr, int len);
void	simplify_array(t_intarr *ia);
int		rotate(t_intarr *ia, int dbl);
int		rrotate(t_intarr *ia, int dbl);
void	push(t_intarr *from, t_intarr *to);
void	swap(t_intarr *ia);
void	print_args(char **argv, int argc);
void	print_arrays(t_intarr *ia, t_intarr *ib, int argc);
void	shift_up(t_intarr *ia);
void	shift_down(t_intarr *ia);
void	end_program(char *er, t_intarr *ia, t_intarr *ib);
void	check_args(char **argv, t_intarr *ia, t_intarr *ib);
void	print_flat(t_intarr *ia, int argc);
void	print_cheapest(t_node *ch);
void	al_3(t_intarr *ia);
void	al_4(t_intarr *ia, t_intarr *ib);
void	init_tch(t_node *tch);
int		find_max(t_intarr *ib);
void	cpy_tch_2_ch(t_node *tch, t_node *ch);
void	make_moves(t_node *ch, t_intarr *ia, t_intarr *ib);
void	move_2_b(t_intarr *ia, t_intarr *ib, t_node *ch, int i);
void	move_2_a(t_intarr *ia, t_intarr *ib);
void	find_a_buddy(t_intarr *ia, t_intarr *ib, t_node *ch, int i);
void	sum_rs(t_node *tch);

#endif
