/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:49:24 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 20:04:50 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_rlst			*search_link(t_rlst *ln, t_room *searched)
{
	while (ln && ln->room_pointer != searched)
		ln = ln->next;
	return (ln);
}
