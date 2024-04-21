/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:23:22 by jponieck          #+#    #+#             */
/*   Updated: 2024/04/21 22:57:38 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int	find_z(const char *nptr)
{
	int	z;

	z = 0;
	while (nptr[z] && (nptr[z] >= 48 && nptr[z] <= 57))
		z++;
	return (z - 1);
}

long int	ft_atoi_long(const char *nptr)
{
	long int	d;
	long int	z;
	long int	i;
	long int	n;

	n = 1;
	while ((*nptr > 8 && *nptr < 14) || *nptr == 32)
		nptr++;
	if (nptr[0] == '-' || nptr[0] == '+')
	{
		n = 44 - nptr[0];
		nptr++;
	}
	d = 1;
	i = 0;
	z = find_z(nptr);
	while (z >= 0)
	{
		i += ((nptr[z] - 48) * d) * n;
		d *= 10;
		z--;
	}
	return (i);
}
