/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:16:44 by jponieck          #+#    #+#             */
/*   Updated: 2024/04/21 20:01:20 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	end_program(char *er, t_intarr *ia, t_intarr *ib)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
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

char	*check_args(char **argv, t_intarr *ia, t_intarr *ib)
{
	int	i;

	argv++;
	while (*argv)
	{
		i = 0;
		while((*argv)[i])
		{
			if (ft_isdigit((*argv)[i]) == 0 && (*argv)[i] != '-')
				end_program("Error\n", ia, ib);
			i++;
		}
		if ((*argv)[i - 1] == '-')
			end_program("Error\n", ia, ib);
		argv++;
	}
}