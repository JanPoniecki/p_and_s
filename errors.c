/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:16:44 by jponieck          #+#    #+#             */
/*   Updated: 2024/04/21 22:52:52 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	end_program(char *er, t_intarr *ia, t_intarr *ib)
{
	if (!er)
	{
		free(ia->ints);
		free(ib->ints);
		exit(0);
	}
	else
	{
		free(ia->ints);
		free(ib->ints);
		ft_putstr_fd(er, 2);
		exit(EXIT_FAILURE);
	}
}

void	check_args(char **argv, t_intarr *ia, t_intarr *ib)
{
	int	i;

	argv++;
	while (*argv)
	{
		i = 0;
		while ((*argv)[i])
		{
			if (ft_isdigit((*argv)[i]) == 0 && (*argv)[i] != '-')
				end_program("Error\n", ia, ib);
			i++;
		}
		if ((*argv)[i - 1] == '-')
			end_program("Error\n", ia, ib);
		if (ft_atoi_long(*argv) > 2147483647 || ft_atoi_long(*argv) < -2147483648)
			end_program("Error\n", ia, ib);
		argv++;
	}
}
