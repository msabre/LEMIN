/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_the_same.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:21:54 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 19:53:57 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		rooms_qsorts(t_room **array, int l, int r)
{
	int			low;
	int			high;
	char		*median;

	low = r;
	high = l;
	median = array[(low + high) / 2]->name;
	while (high <= low)
	{
		while (ft_strcmp(array[high]->name, median) < 0)
			high++;
		while (ft_strcmp(array[low]->name, median) > 0)
			low--;
		if (high <= low)
			ft_memswap((void**)array, high++, low--);
	}
	if (l < low)
		rooms_qsorts(array, l, low);
	if (r > high)
		rooms_qsorts(array, high, r);
}

static void		error_out_config(t_general *all, char *str, char *message)
{
	int		i;

	all->error_message = message;
	i = search_mem(str, all->map_output.array,
		all->map_output.index, 0);
	i = search_mem(str, all->map_output.array,
		all->map_output.index, i + 1);
	all->map_output.result = i + 1;
}

int				search_same_links(t_general *all)
{
	int		duplicate;

	str_qsorts((char**)(all->links_r).array, 0, all->links_r.index - 1);
	duplicate = check_duplicates((char**)all->links_r.array,
		all->links_r.index);
	if (duplicate > -1)
	{
		error_out_config(all, all->links_r.array[duplicate],
			"duplicates links\n");
		return (0);
	}
	return (1);
}

int				search_same_coor(t_general *all)
{
	int		duplicate;
	int		i;

	str_qsorts((char**)(all->coor).array, 0, all->coor.index - 1);
	duplicate = check_duplicates((char**)all->coor.array, all->coor.index);
	if (duplicate > -1)
	{
		all->error_message = "duplicate coordination\n";
		i = search_coor(&all->map_output,
			all->coor.array[duplicate], 0);
		i = search_coor(&all->map_output,
			all->coor.array[duplicate], i + 1);
		all->map_output.result = i + 1;
		return (0);
	}
	return (1);
}

int				search_same_rooms(t_general *all)
{
	int		duplicate;
	char	*str;

	rooms_qsorts((t_room **)(all->rooms).array, 0,
		all->rooms.index - 1);
	duplicate = check_rooms_duplicates((t_room **)all->rooms.array,
		all->rooms.index);
	if (duplicate > -1)
	{
		str = ((t_room*)all->rooms.array[duplicate])->name;
		error_out_config(all, str, "duplicate rooms\n");
		return (0);
	}
	return (1);
}
