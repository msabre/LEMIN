/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:40:40 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 20:20:13 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			rooms_free(t_arraylist *array)
{
	t_room		*room;
	int			i;

	i = 0;
	while (i < array->index)
	{
		room = array->array[i];
		if (room->out)
		{
			free_way(room->out->links);
			free(room->out);
		}
		free_way(room->links);
		free(room->name);
		free(room);
		i++;
	}
	free(array->array);
}

void			free_content(t_general *all)
{
	int			i;

	i = 0;
	rooms_free(&all->rooms);
	if (all->paths.array)
		free_paths((t_rlst**)all->paths.array, all->paths.index);
	all->links_r.arr_del(&all->links_r);
	if (all->flags.i == 0)
	{
		free(all->queue.array);
		free(all->paths_copies.array);
		free(all->collision.array);
		free(all->paths.array);
	}
	free(all->coor.array);
}
