/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:55:31 by jponieck          #+#    #+#             */
/*   Updated: 2024/04/21 10:46:42 by jponieck         ###   ########.fr       */
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
	char	col;
	int		args;
	int		moves_count;
	int		max;
	int		min;
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
void	swap(t_intarr *ia, t_intarr *ib);
void	print_args(char **argv, int argc);
void	print_arrays(t_intarr *ia, t_intarr *ib, int argc);
void	shift_up(t_intarr *ia);
void	shift_down(t_intarr *ia);
void	end_program(char *er, t_intarr *ia, t_intarr *ib);
char	*check_args(char **argv, t_intarr *ia, t_intarr *ib);
void	print_flat(t_intarr *ia, int argc);
void	print_cheapest(t_node *ch);
void	al_3(t_intarr *ia, t_intarr *ib);
void	al_4(t_intarr *ia, t_intarr *ib, char **argv);

#endif
