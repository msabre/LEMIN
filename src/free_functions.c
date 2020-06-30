/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 21:33:13 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 20:23:57 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		free_way_part(t_rlst *path, int count)
{
	t_rlst	*tmp;
	int		i;

	i = 0;
	while (i < count)
	{
		tmp = path->next;
		free(path);
		path = tmp;
		i++;
	}
}

void		free_way(t_rlst *path)
{
	if (!path)
		return ;
	while (path->next != NULL)
	{
		path = path->next;
		free(path->prev);
	}
	free(path);
}

void		free_paths(t_rlst **paths, int size)
{
	int		i;

	i = 0;
	if (!paths)
		return ;
	while (i < size)
	{
		free_way(paths[i]);
		paths[i] = NULL;
		i++;
	}
}
