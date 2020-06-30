/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:03:56 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 18:23:27 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				length_path(t_rlst *path)
{
	int			count;

	count = 0;
	while (path)
	{
		path = path->next;
		count++;
	}
	return (count - 1);
}
