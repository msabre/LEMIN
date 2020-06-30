/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:47:16 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 20:45:00 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		disconnect_link(t_room **room, t_rlst *link)
{
	if (link->prev && link->next)
	{
		link->prev->next = link->next;
		link->next->prev = link->prev;
	}
	else if (link->prev)
		link->prev->next = NULL;
	else if (link->next)
	{
		(*room)->links = (*room)->links->next;
		(*room)->links->prev = NULL;
	}
	else if (link)
		(*room)->links = NULL;
	link->prev = NULL;
}

void		change_links(t_room **source, t_room *new_owner, t_rlst *link)
{
	disconnect_link(source, link);
	link->next = new_owner->links;
	if (new_owner->links)
		new_owner->links->prev = link;
	new_owner->links = link;
}
