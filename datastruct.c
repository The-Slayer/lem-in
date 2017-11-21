/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datastruct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 13:42:31 by hstander          #+#    #+#             */
/*   Updated: 2017/11/21 15:03:26 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_frees(t_args *ag)
{
	if (ag->line != NULL)
	{
		free(ag->line);
		ag->line = NULL;
	}
	if (ag->links != NULL)
	{
		ft_free2d(ag->links);
		ag->links = NULL;
	}
	if (ag->args != NULL)
	{
		ft_free2d(ag->args);
		ag->args = NULL;
	}
}

void	ft_rooms(t_vars *vs, t_args *ag)
{
	if (ft_arrlen(ag->args) > 3)
		ft_exit();
	ag->rooms[vs->r_i] = (t_room *)ft_memalloc(sizeof(t_room));
	ag->rooms[vs->r_i]->name = ft_strdup(ag->args[0]);
	if (vs->start == 1)
	{
		ag->rooms[vs->r_i]->start = 1;
		vs->start = 0;
	}
	if (vs->end == 1)
	{
		vs->end = 0;
		ag->rooms[vs->r_i]->end = 1;
	}
	vs->r_i++;
}
#include <stdio.h>
void	ft_links(t_vars *vs, t_args *ag)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	vs->b_i = 0;
	vs->e_i = 0;
	ag->links = ft_strsplit(ag->args[0], '-');
	if (ft_arrlen(ag->links) > 2 || ag->rooms[vs->b_i] == NULL)
		ft_exit();
	while (ft_strcmp(ag->rooms[vs->b_i]->name, ag->links[0]) != 0)
		if (ag->rooms[++vs->b_i] == NULL)
			ft_exit();
	while (ft_strcmp(ag->rooms[vs->e_i]->name, ag->links[1]) != 0)
		if (ag->rooms[++vs->e_i] == NULL)
			ft_exit();
	while (ag->rooms[vs->b_i]->room[i])
		i++;
	while (ag->rooms[vs->e_i]->room[j])
		j++;
	ag->rooms[vs->b_i]->room[i] = ag->rooms[vs->e_i];
	ag->rooms[vs->e_i]->room[j] = ag->rooms[vs->b_i];
}

void	ft_startend(t_vars *vs, t_args *ag)
{
	if (ft_strstr(ag->line, "start") != NULL)
		vs->start = 1;
	else if (ft_strstr(ag->line, "end") != NULL)
		vs->end = 1;
}

void	ft_datastruct(t_vars *vs, t_args *ag)
{
	while (get_next_line(0, &ag->line) != 0)
	{
		if ((vs->cntr < 1) && (ft_digit(ag) == 1))
		{
			vs->ants = ft_atoi(ag->line);
			vs->cntr++;
		}
		else if (vs->cntr > 0)
		{
			if (ag->line[0] == '#')
				ft_startend(vs, ag);
			else
			{
				ag->args = ft_strsplit(ag->line, ' ');
				if (ag->args[0] == '\0')
					ft_exit();
				else if (ag->args[1] == NULL)
					ft_links(vs, ag);
				else
					ft_rooms(vs, ag);
			}
		}
		ft_frees(ag);
	}
}
