/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:28:42 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 20:05:35 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		define_x_y(char *ptr, int *x, int *y)
{
	*x = ft_atoi(ptr);
	while (is_num(*ptr))
		ptr++;
	while (*ptr == ' ')
		ptr++;
	*y = ft_atoi(ptr);
}

void			new_room(char *name, char *coordination, t_arraylist *array)
{
	t_room		*room;

	room = (t_room*)ft_memalloc(sizeof(t_room));
	if (!room)
		exit(-1);
	define_x_y(coordination, &room->x, &room->y);
	room->name = name;
	room->length = INT32_MAX;
	array->add_doub(array, room);
	if (array->result == -1)
		exit(-1);
}
