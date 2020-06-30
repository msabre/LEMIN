/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:14:40 by msabre            #+#    #+#             */
/*   Updated: 2020/02/24 18:57:47 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/get_next_line.h"

static t_gnlist		*fd_find(t_gnlist **list, int fd)
{
	t_gnlist		*right_list;

	right_list = *list;
	while (right_list)
	{
		if (right_list->content_size == fd)
			break ;
		right_list = right_list->next;
	}
	if (right_list == NULL)
	{
		right_list = (t_gnlist*)malloc(sizeof(t_gnlist));
		right_list->content = ft_strnew(1);
		right_list->content_size = fd;
		ft_lstadd(list, right_list);
	}
	return (right_list);
}

static int			ft_find_chr_in(char *buffer)
{
	int				i;

	i = 0;
	if (!buffer)
		return (-1);
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
		{
			buffer[i] = '\0';
			return (i);
		}
		i++;
	}
	return (-1);
}

static int			ft_readline(int fd, t_gnlist **list, char ***line)
{
	char			buffer[BUFF_SIZE + 1];
	char			*stat;
	int				i;

	while ((i = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[i] = '\0';
		stat = (*list)->content;
		if ((i = ft_find_chr_in(buffer)) > -1)
		{
			**line = ft_strjoin((*list)->content, buffer);
			(*list)->content = ft_strdup(buffer + i + 1);
			ft_strdel(&stat);
			return (1);
		}
		(*list)->content = ft_strjoin((*list)->content, buffer);
		ft_strdel(&stat);
	}
	if ((*list)->content && (*list)->content[0] != '\0')
	{
		**line = ft_strdup((*list)->content);
		ft_strdel(&(*list)->content);
		return (1);
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static t_gnlist	*list;
	t_gnlist		*right_list;
	char			*mem;
	char			*stat;
	int				i;

	mem = NULL;
	if (!line || fd < 0 || (read(fd, (void*)mem, 0)) < 0)
		return (-1);
	right_list = fd_find(&list, fd);
	if ((i = ft_find_chr_in(right_list->content)) > -1)
	{
		stat = right_list->content;
		*line = ft_strdup(right_list->content);
		right_list->content = ft_strdup(right_list->content + i + 1);
		ft_strdel(&stat);
		return (1);
	}
	i = ft_readline(fd, &right_list, &line);
	return (i);
}
