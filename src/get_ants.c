/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:18:12 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 20:42:29 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		initial_before_ant(t_general *all, char *line)
{
	all->map_output.result = all->map_output.index + 1;
	all->error_message = (ft_strcmp(line, "##start") == 0)
		? "start initial before ants\n" : "end initial before ants\n";
	all->cn_ants = -1;
	free(line);
}

static int		ants_error_managment(t_arraylist *map_output,
	char *line, char **error)
{
	if (*line == '\0')
	{
		*error = "empty line\n";
		map_output->result = map_output->index;
		return (0);
	}
	if (count_words(line, ' ') > 1)
	{
		*error = "more digits, than 1\n";
		map_output->result = map_output->index;
		return (0);
	}
	if (*line == '-')
	{
		*error = "invalid ants count\n";
		map_output->result = map_output->index;
		return (0);
	}
	if (!is_numvalue(line))
	{
		*error = "it's not integer\n";
		map_output->result = map_output->index;
		return (0);
	}
	return (1);
}

static int		get_ants(t_arraylist *map_output, char *line, char **error)
{
	long		cn_ants;

	cn_ants = 0;
	map_output->add_doub(map_output, line);
	if (map_output->result == -1)
		exit(-1);
	if (!ants_error_managment(map_output, line, error))
		return (-1);
	cn_ants = ft_atoi(line);
	if (cn_ants <= 0 || cn_ants > INT32_MAX)
	{
		*error = "invalid ants count\n";
		map_output->result = map_output->index;
		cn_ants = -1;
	}
	return (cn_ants);
}

static int		check_start_end_before(t_general *all, char *line)
{
	if (ft_strcmp(line, "##start") == 0 || ft_strcmp(line, "##end") == 0)
	{
		initial_before_ant(all, line);
		return (1);
	}
	return (0);
}

void			find_ants_count(t_general *all)
{
	char		*line;

	while (!all->cn_ants && get_next_line(0, &line) > 0)
	{
		if (line[0] == '#')
		{
			if (line[1] == '#')
				if (check_start_end_before(all, line))
					return ;
			if (all->map_output.add_doub(&all->map_output, line) == -1)
				exit(-1);
		}
		else
		{
			all->cn_ants = get_ants(&all->map_output,
				line, &(all->error_message));
			return ;
		}
	}
	all->error_message = "file empty or does not exist\n";
	all->map_output.result = 0;
}
