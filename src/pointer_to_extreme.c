/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_to_extreme.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:41:27 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 20:02:23 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		new_path(t_rlst *zveno)
{
	t_room		*reader;
	t_rlst		*link;

	reader = zveno->room_pointer;
	link = search_link(reader->out->links, reader->parent);
	change_links(&(reader->out), reader, link);
}

static void		access_ret(t_room *source, t_room *verifiable)
{
	t_rlst		*ln;

	ln = search_link(source->links, verifiable->out);
	change_links(&source, source->out, ln);
	ln->cost = 1;
	ln->room_pointer = verifiable;
	ln = search_link(verifiable->out->links, source);
	ln->access = 1;
}

static void		glue_rooms(t_room *room, t_room *prev)
{
	t_rlst		*tmp;

	if (!room->out)
		return ;
	room->links->cost = 1;
	room->links->room_pointer = ((t_room*)room->links->room_pointer)->in;
	room->affiliation = NULL;
	room->split = 0;
	while (room->out->links)
	{
		if (room->out->links->room_pointer == room)
		{
			tmp = room->out->links;
			disconnect_link(&(room->out), room->out->links);
		}
		else
		{
			if (room->out->links->room_pointer == prev)
				room->out->links->access = 1;
			change_links(&(room->out), room, room->out->links);
		}
	}
	room->out->links = tmp;
	tmp->next = NULL;
}

int				pointers_to_extreme(t_rlst **source, t_rlst **verifiable)
{
	int			count;

	count = 1;
	new_path(*source);
	access_ret((*source)->room_pointer, (*source)->prev->room_pointer);
	*source = (*source)->prev;
	*verifiable = (*verifiable)->next;
	while ((*source)->prev && (*verifiable)->next
	&& (*source)->prev->room_pointer == (*verifiable)->next->room_pointer)
	{
		glue_rooms((*source)->room_pointer, (*source)->next->room_pointer);
		*source = (*source)->prev;
		*verifiable = (*verifiable)->next;
		count++;
	}
	return (count);
}
