/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:55:31 by jponieck          #+#    #+#             */
/*   Updated: 2024/04/18 22:27:23 by jponieck         ###   ########.fr       */
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
	char	*moves;
	char	col;
	int		next_n;
	int		args;
	int		moves_count;
	int		alg_id;
}	t_intarr;

typedef struct s_node
{
	int	b_index;
	int	rbs;
	int	ras;
	int	rb_dir;
	int	ra_dir;
}	t_node;

void	decrease(int nr, int *arr, int len);
void	fill_up_array(t_intarr *ia, char **src);
int		next_one(int *iarr, int len);
void	simplify_array(t_intarr *ia);
void	rotate(t_intarr *ia, int dbl);
void	rrotate(t_intarr *ia, int dbl);
void	append_move(t_intarr *ia, char *move);
void	push(t_intarr *from, t_intarr *to);
void	swap(t_intarr *ia, t_intarr *ib);
void	print_args(char **argv, int argc);
void	print_arrays(t_intarr *ia, t_intarr *ib, int argc);
int		pick_nearest(t_intarr *ia, int s, int s2);
int		find_nearest_index(t_intarr *ia, int s, int s2, int i);
void	move_nearest(t_intarr *ia);
void	move_from_a(t_intarr *ia, t_intarr *ib);
void	move_from_b(t_intarr *ib, t_intarr *ia);
void	shift_up(t_intarr *ia);
void	shift_down(t_intarr *ia);
int		is_sorted(t_intarr *ia);
int		swap_will_sort(t_intarr *ia);
void	end_program(char *er, t_intarr *ia, t_intarr *ib);
char	*check_args(char **argv, t_intarr *ia, t_intarr *ib);
void	print_flat(t_intarr *ia, int argc);
int		al_1(t_intarr *ia, t_intarr *ib, char **argv);
int		al_2(t_intarr *ia, t_intarr *ib, char **argv);
void	al_3(t_intarr *ia, t_intarr *ib, int max_a);
void	al_4(t_intarr *ia, t_intarr *ib, char **argv);
int		absolute(int x);
void	set_direction(t_node *cheapest, int way_a, int way_b);
void	find_b_buddy(t_intarr *ia, t_intarr *ib, t_node *cheapest, int a_index);
char	is_in_stack(t_intarr *ia, int x);
void	meet_buddies(t_intarr *ia, t_intarr *ib, t_node *cpst);

#endif
