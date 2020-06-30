/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_in_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:45:44 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 19:39:44 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		set_affiliation(t_rlst *path)
{
	t_room		*reader;
	t_rlst		*start;

	start = path;
	while (path && path->next)
	{
		reader = path->room_pointer;
		reader->affiliation = start;
		path = path->next;
	}
}

static void		reverse_edges(t_rlst *path)
{
	t_room		*reader;
	t_rlst		*ln;
	t_rlst		*next;

	reader = path->prev->room_pointer;
	ln = search_link(reader->links, path->room_pointer);
	(ln) ? ln->access = 0 : ln->access;
	while (path)
	{
		reader = path->room_pointer;
		ln = search_link(reader->links, path->prev->room_pointer);
		if (ln)
		{
			if (((t_room*)ln->room_pointer)->out)
				ln->room_pointer = ((t_room*)ln->room_pointer)->out;
			ln->cost = -1;
		}
		if (path->next)
		{
			next = search_link(reader->out->links, path->next->room_pointer);
			if (next)
				next->access = 0;
		}
		path = path->next;
	}
}

static void		links_to_out(t_room *reader, t_room *prev)
{
	t_rlst		*ln;

	while (reader->links)
	{
		if (reader->links->room_pointer != prev)
			change_links(&(reader), reader->out, reader->links);
		else
		{
			ln = reader->links;
			reader->links = reader->links->next;
			if (reader->links)
				reader->links->prev = NULL;
			ln->next = NULL;
		}
	}
	reader->links = ln;
}

static t_room	*add_outroom(t_room *room)
{
	t_room		*new;

	if (room->out)
	{
		room->split = 1;
		return (room->out);
	}
	new = (t_room*)ft_memalloc(sizeof(t_room));
	if (!new)
		exit(-1);
	room->split = 1;
	new->name = room->name;
	new->length = INT32_MAX;
	new->searched = 0;
	new->split = 1;
	new->in = room;
	return (new);
}

int				split_in_out(t_rlst *path, t_room *end)
{
	t_rlst		*start;
	t_room		*reader;

	start = path;
	while (path && path->next)
	{
		reader = path->room_pointer;
		if (reader != end && reader->split == 0)
		{
			reader->out = add_outroom(reader);
			lst_rooms(&(reader->out->links), reader, 0, 1);
			links_to_out(reader, path->prev->room_pointer);
		}
		path = path->next;
	}
	reverse_edges(start);
	set_affiliation(start->prev);
	return (1);
}
