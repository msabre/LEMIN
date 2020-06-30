/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:06:41 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 20:05:56 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				lst_rooms(t_rlst **list, t_room *new, int cost, int access)
{
	t_rlst		*tmp;
	t_rlst		*ptr;
	int			i;

	i = 0;
	ptr = (t_rlst*)malloc(sizeof(t_rlst));
	if (!ptr)
		exit(-1);
	ptr->room_pointer = new;
	ptr->cost = cost;
	ptr->access = access;
	ptr->next = NULL;
	if (!(*list))
	{
		ptr->prev = NULL;
		*list = ptr;
		return (1);
	}
	tmp = *list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = ptr;
	ptr->prev = tmp;
	return (1);
}
