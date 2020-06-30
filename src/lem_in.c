/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 18:14:29 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 20:08:40 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		print_paths(t_rlst **paths, int count)
{
	t_room		*reader;
	t_rlst		*tmp;
	int			common;
	int			i;

	i = 0;
	common = 1;
	ft_printf("\n# Total paths count: %d\n\n", count);
	while (paths[i] != NULL)
	{
		tmp = paths[i];
		ft_printf("\nPath %d length of %d [ ", common, length_path(tmp));
		while (tmp != NULL)
		{
			reader = tmp->room_pointer;
			ft_printf("%s ", reader->name);
			tmp = tmp->next;
		}
		common++;
		write(1, "]\n", 3);
		i++;
	}
	write(1, "\n", 1);
}

static void		solutions_structs_initial(t_general *all)
{
	all->cm_len = 0;
	all->actual = LONG_MAX;
	init(&all->paths, 10);
	init(&all->paths_copies, 0);
	init(&all->collision, 0);
	init(&all->queue, all->rooms.index * 1.5);
}

int				lem_in(t_general *all)
{
	int			res;
	int			*ways_lens;

	if (all->flags.i == 1)
		return (1);
	solutions_structs_initial(all);
	res = 1;
	while (all->paths.index < all->cn_ants && res)
		res = launch_alg(all);
	if (all->paths.index == 0)
	{
		ft_printf("Path not found\n\n*Change links and try again*\n\n");
		return (1);
	}
	all->paths.array[all->paths.index] = NULL;
	ways_lens = sort_paths((t_rlst**)all->paths.array, all->paths.index);
	if (all->flags.p == 1)
	{
		print_paths((t_rlst**)all->paths.array, all->paths.index);
		free(ways_lens);
		return (1);
	}
	let_ants_go(all, ways_lens);
	return (1);
}
