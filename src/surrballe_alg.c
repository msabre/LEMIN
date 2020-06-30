/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surrballe_alg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 18:35:16 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 19:33:09 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		refresh_searched(t_room **mass, int size)
{
	int			i;

	i = 0;
	while (i < size)
	{
		(mass[i])->parent = NULL;
		(mass[i])->searched = 0;
		(mass[i])->length = INT32_MAX;
		if (mass[i]->out)
		{
			(mass[i])->out->parent = NULL;
			(mass[i])->out->searched = 0;
			(mass[i])->out->length = INT32_MAX;
		}
		i++;
	}
}

static void		set_last_variant(t_general *all)
{
	int			get_num;
	int			i;

	i = 0;
	while (i < all->paths_copies.index)
	{
		get_num = ((t_rlst *)all->paths_copies.array[i])->path_number;
		free_way(all->paths.array[get_num]);
		all->paths.array[get_num] = all->paths_copies.array[i];
		i++;
	}
	free_way(all->paths.array[all->paths.index - 1]);
	all->paths.index -= 1;
}

static long		get_turns(t_general *all, int count)
{
	long		turns;
	long		del;

	del = all->cm_len + all->cn_ants;
	if (del % count == 0)
		turns = (del / count) - 1;
	else
		turns = del / count;
	return (turns);
}

static int		summary_changed_lengths(t_general *all)
{
	int			len;
	int			num;
	int			i;

	i = 0;
	len = 0;
	while (i < all->collision.index)
	{
		num = ((t_rlst *)all->collision.array[i])->path_number;
		len += length_path(all->paths.array[num]);
		i++;
	}
	all->collision.lzero(&(all->collision));
	return (len);
}

int				launch_alg(t_general *all)
{
	long		res;

	if (!belmonford_alg(all))
		return (0);
	if (all->collision.index > 0)
	{
		res = collisions_rem(all);
		all->cm_len += summary_changed_lengths(all);
	}
	else
		split_in_out(((t_rlst *)all->paths.array[all->paths.index - 1])->next,
			all->end);
	all->cm_len += length_path(all->paths.array[all->paths.index - 1]);
	res = get_turns(all, all->paths.index);
	if (res > all->actual)
	{
		set_last_variant(all);
		return (0);
	}
	free_paths((t_rlst **)all->paths_copies.array, all->paths_copies.index);
	all->paths_copies.index = 0;
	all->actual = res;
	refresh_searched((t_room **)all->rooms.array, all->rooms.index);
	return (1);
}
