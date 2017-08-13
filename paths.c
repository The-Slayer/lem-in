/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 13:42:41 by hstander          #+#    #+#             */
/*   Updated: 2017/08/13 16:17:43 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_path_tofile(t_path *head, int fd)
{
	while (head && head->data)
	{
		write(fd, head->data, ft_strlen(head->data));
		write(fd, " ", 1);
		head = head->next;
	}
	write(fd, "\n", ft_strlen("\n"));
}

void	ft_path(t_room *st, t_path *head, t_path *list, int fd)
{
	int		i;
	t_path	*next;

	i = 0;
	list->next = (t_path *)ft_memalloc(sizeof(t_path));
	st->visit = 1;
	list->data = st->name;
	next = list->next;
	if (st->end == 1)
	{
		ft_path_tofile(head, fd);
	}
	while (st->room[i] && st->end == 0)
	{
		if (st->room[i]->visit == 0)
		{
			ft_path(st->room[i], head, next, fd);
		}
		i++;
	}
	list->data = NULL;
	free(next);
	list = NULL;
	st->visit = 0;
}

void	ft_paths(t_vars *vs, t_args *ag)
{
	t_path	*list;
	int		j;
	int		fd;

	j = 0;
	fd = open("path", O_TRUNC | O_WRONLY);
	list = (t_path *)ft_memalloc(sizeof(t_path));
	ft_path(ag->rooms[vs->start], list, list, fd);
	free(list);
	close(fd);
	fd = open("path", O_RDONLY);
	ag->paths = (char ***)ft_memalloc(sizeof(char **) * 10000);
	while (get_next_line(fd, &ag->line))
	{
		ag->paths[j] = ft_strsplit(ag->line, ' ');
		free(ag->line);
		j++;
	}
	ft_sort(ag->paths);
	close(fd);
}

void	ft_sort(char ***arr)
{
	char	**ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (ft_arrlen(arr[i]) > ft_arrlen(arr[j]))
			{
				ptr = arr[i];
				arr[i] = arr[j];
				arr[j] = ptr;
			}
			j++;
		}
		i++;
	}
}
