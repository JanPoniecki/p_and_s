/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:31:06 by jponieck          #+#    #+#             */
/*   Updated: 2024/04/20 21:10:54 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	decrease(int nr, int *arr, int len)
{
	int	i;
	int	c;

	i = 0;
	c = -1;
	while (i < len)
	{
		if (arr[i] == nr)
			c = i;
		i++;
	}
	if (c > -1)
	{
		decrease(nr -1, arr, len);
		arr[c] = nr - 1;
	}
	else
		return ;
}

void	fill_up_array(t_intarr *ia, char **src)
{
	int	i;

	i = 1;
	while (src[i])
	{
		ia->ints[i - 1] = ft_atoi(src[i]);
		i++;
	}
}

int	next_one(int *iarr, int len)
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
	return (min);
}

void	simplify_array(t_intarr *ia)
{
	int	*temp_arr;
	int	min;
	int	i;

	temp_arr = ft_calloc(ia->len, sizeof(int));
	ft_memcpy(temp_arr, ia->ints, ia->len * sizeof(int));
	i = 0;
	decrease(2147483647, temp_arr, ia->len);
	while (i < ia->len)
	{
		min = next_one(temp_arr, ia->len);
		ia->ints[min] = i + 1;
		temp_arr[min] = 2147483647;
		i++;
	}
	free (temp_arr);
}
