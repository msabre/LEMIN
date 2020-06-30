/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   belmonford_alg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:55:19 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 20:25:03 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		add_to_queue(t_room *room, t_arraylist *queue, int *change)
{
	t_room		*reader;
	t_rlst		*links;

	links = room->links;
	while (links)
	{
		if (links->access == 1)
		{
			reader = links->room_pointer;
			if (reader->length > room->length + links->cost)
			{
				reader->length = room->length + links->cost;
				reader->parent = room;
				(*change)++;
			}
			if (reader->searched == 0)
			{
				queue->array[queue->index++] = reader;
				queue->size++;
				reader->searched = 1;
			}
		}
		links = links->next;
	}
	queue->size--;
}

static void		add_links_from_start(t_general *all, int *change, int *index)
{
	*change = 0;
	*index = 0;
	all->queue.size = 1;
	all->queue.index = 0;
	add_to_queue(all->start, &all->queue, change);
	all->start->searched = 1;
}

int				belmonford_alg(t_general *all)
{
	t_rlst		*path;
	int			index;
	int			cn_rooms;
	int			change;

	all->start->length = 0;
	cn_rooms = (all->rooms.index + 2) - 1;
	while (cn_rooms > 0)
	{
		add_links_from_start(all, &change, &index);
		while (all->queue.size > 0)
			add_to_queue(all->queue.array[index++], &all->queue, &change);
		if (change == 0)
			break ;
		info_refresh(all);
		cn_rooms--;
	}
	if (!all->end->parent)
		return (0);
	drop_bifurcations(all->end);
	path = create_path(all->end);
	path->path_number = all->paths.index;
	all->paths.add_doub(&all->paths, path);
	collision_check(path->next, &all->collision);
	return (1);
}
