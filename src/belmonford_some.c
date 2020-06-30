/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   belmonford_some.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:56:58 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 20:22:52 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			drop_bifurcations(t_room *room)
{
	t_room		*tmp;

	while (room->parent)
	{
		if (room->parent->split == 1)
		{
			if (room->parent->out == NULL)
			{
				tmp = room->parent->parent;
				room->parent = room->parent->in;
				if (tmp != room->parent)
					room->parent->parent = tmp;
			}
		}
		room = room->parent;
	}
}

void			info_refresh(t_general *all)
{
	int			i;

	i = 0;
	while (i < all->rooms.index)
	{
		((t_room*)all->rooms.array[i])->searched = 0;
		if (((t_room*)all->rooms.array[i])->out)
			((t_room*)all->rooms.array[i])->out->searched = 0;
		i++;
	}
	all->queue.size = 0;
	all->queue.index = 0;
	all->start->searched = 1;
}

void			collision_check(t_rlst *path, t_arraylist *collision)
{
	t_room		*path_room;
	t_room		*coll_room;
	int			j;

	while (path && path->next)
	{
		path_room = path->room_pointer;
		if (path_room->affiliation)
		{
			j = -1;
			while (++j < collision->index)
			{
				coll_room = ((t_rlst*)collision->array[j])->next->room_pointer;
				if (path_room->affiliation == coll_room->affiliation)
					break ;
			}
			if (j == collision->index)
			{
				collision->add_doub(collision, path_room->affiliation);
				if (collision->result == -1)
					exit(-1);
			}
		}
		path = path->next;
	}
}

t_rlst			*create_path(t_room *end)
{
	t_rlst		*new;
	t_rlst		*path;
	t_room		*parent;

	path = (t_rlst*)ft_memalloc(sizeof(t_rlst));
	path->room_pointer = end;
	if (!path)
		exit(-1);
	path->next = NULL;
	parent = end->parent;
	while (parent)
	{
		new = (t_rlst*)ft_memalloc(sizeof(t_rlst));
		if (!new)
			exit(-1);
		new->room_pointer = parent;
		new->next = path;
		path->prev = new;
		path = new;
		parent = parent->parent;
	}
	return (path);
}
