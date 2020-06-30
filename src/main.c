/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:04:06 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 19:58:24 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		help_print(void)
{
	ft_putstr("lem-in (c) 2020 msabre | bbutterm\n\n"
			"usage:  ./lem-in < filename\n\n"
			"The goal of the project is to find many of the shortest disjoint\n"
			"paths for transferring ants from room ##start to room ##end"
			"in the least number of moves\n\n"
			"Options:\n"
			"	-i, --input     raw input\n"
			"	-p, --paths     selected paths and ant distribution\n"
			"	-t, --turns     total number of turns\n"
			"	-m, --moves     lists of moves made at each turn\n"
			"	-h, --help      only this help\n");
}

static int		initial_flags(char *argv, t_flags *flags)
{
	if (ft_strcmp(argv, "-t") == 0)
		flags->t = 1;
	else if (ft_strcmp(argv, "-p") == 0)
		flags->p = 1;
	else if (ft_strcmp(argv, "-m") == 0)
		flags->m = 1;
	else if (ft_strcmp(argv, "-h") == 0)
		flags->h = 1;
	else if (ft_strcmp(argv, "-i") == 0)
		flags->i = 1;
	else
	{
		ft_putstr("usage: ./lem-in [options] < filename\n");
		return (0);
	}
	return (1);
}

int				main(int argc, char **argv)
{
	t_general	all;

	ft_bzero(&(all.flags), sizeof(t_flags));
	if (argc == 2)
	{
		if (!initial_flags(argv[1], &all.flags))
			return (0);
		if (all.flags.h == 1)
		{
			help_print();
			return (0);
		}
	}
	else if (argc > 2)
	{
		ft_printf("usage: ./lem-in [options] < filename\n");
		return (0);
	}
	start_solution(&all);
	return (0);
}
