/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 09:50:30 by hstander          #+#    #+#             */
/*   Updated: 2017/07/31 15:19:15 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		main(void)
{
	char	*line;
	t_room	*rooms[1000];
	char	**args;
	int		start;
	int		end;
	char	**links;
	int		r_i;
	int		b_i;
	int		e_i;
	int 	cntr;
	int 	i = 0;

	cntr = 0;
	r_i = 0;
	start = 0;
	end = 0;
	b_i = 0;
	e_i = 0;
	line = NULL;
	args = NULL;
	links = NULL;
	while (get_next_line(0, &line) != 0)
	{
		if (line[0] == '#')
		{
			if (ft_strstr(line, "start") != NULL)
				start = 1;
			else if (ft_strstr(line, "end") != NULL)
				end = 1;
		}
		else 
		{
			args = ft_strsplit(line, ' ');
			i = 0;
			if (args[1] == NULL && cntr > 0)
			{
				links = ft_strsplit(args[0], '-');
				b_i = 0;
				while (ft_strcmp(rooms[b_i]->name, links[0]) != 0)
					b_i++;
				e_i = 0;
				while (ft_strcmp(rooms[e_i]->name, links[1]) != 0)
					e_i++;
				while (rooms[b_i]->room[i])
					i++;
				rooms[b_i]->room[i] = rooms[e_i];
				printf("********* %s\n", rooms[b_i]->room[i]->name);
			}
			else if (cntr > 0)
			{
				rooms[r_i] = (t_room *)ft_memalloc(sizeof(t_room));
				rooms[r_i]->name = ft_strdup(args[0]);
				if (start == 1)
				{
					rooms[r_i]->start = 1;
					start = 0;
				}
				if (end == 1)
				{
					end = 0;
					rooms[r_i]->end = 1;
				}
				printf("--> %s\n", rooms[r_i]->name);
				printf("--> start = %d end = %d\n", rooms[r_i]->start, rooms[r_i]->end);
				r_i++;
			}
		}
		if (line != NULL)
		{
			free(line);
			line = NULL;
		}
		if (links != NULL)
		{
			ft_free2d(links);
			links = NULL;
		}
		if (args != NULL)
		{
			ft_free2d(args);
			args = NULL;
		}
		cntr++;
	}
	if (line != NULL)
		free(line);

	return (0);
}
