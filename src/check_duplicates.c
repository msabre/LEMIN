/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:29:46 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 20:43:45 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			check_rooms_duplicates(t_room **array, int size)
{
	int		i;

	i = 0;
	while (i < size - 1)
	{
		if (ft_strcmp(array[i]->name, array[i + 1]->name) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int			check_duplicates(char **array, int size)
{
	int		i;

	i = 0;
	while (i < size - 1)
	{
		if (ft_strcmp(array[i], array[i + 1]) == 0)
			return (i);
		i++;
	}
	return (-1);
}
