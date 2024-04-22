/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:16:44 by jponieck          #+#    #+#             */
/*   Updated: 2024/04/22 22:39:35 by jponieck         ###   ########.fr       */
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

void	check_unique(char **argv, t_intarr *ia, t_intarr *ib)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (argv[i])
	{
		while (argv[j])
		{
			if (ft_strncmp(argv[i], argv[j], 12) == 0)
				end_program("Error\n", ia, ib);
			j++;
		}
		i++;
		j = i + 1;
	}
}

void	check_args(char **argv, t_intarr *ia, t_intarr *ib)
{
	long int	i;

	argv++;
	check_unique(argv, ia, ib);
	while (*argv)
	{
		if (!ft_strncmp("0", *argv, 2) || !ft_strncmp("-0", \
				*argv, 3) || !ft_strncmp("+0", *argv, 3))
		{
			argv++;
			continue ;
		}
		i = ft_atoi_long(*argv);
		if (i > 2147483647 || i < -2147483648 || i == 0)
			end_program("Error\n", ia, ib);
		argv++;
	}
}
