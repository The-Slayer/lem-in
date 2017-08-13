/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 09:50:30 by hstander          #+#    #+#             */
/*   Updated: 2017/08/13 17:17:59 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_exit(void)
{
	ft_putendl("ERROR");
	exit(0);
}

size_t	ft_arrlen(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	ft_start_end(t_vars *vs, t_args *ag)
{
	vs->start = 0;
	vs->end = 0;
	while (ag->rooms[vs->start]->start == 0)
		vs->start++;
	while (ag->rooms[vs->end]->end == 0)
		vs->end++;
	ag->rooms[vs->start]->full = vs->ants;
}

void	ft_ant_names(t_vars *vs, t_args *ag)
{
	int		i;

	i = 0;
	ag->ants_n = (t_ant **)ft_memalloc(sizeof(t_ant *) * (vs->ants + 1));
	while (i < vs->ants)
	{
		ag->ants_n[i] = (t_ant *)ft_memalloc(sizeof(t_ant));
		ag->ants_n[i]->name = ft_itoa(i + 1);
		ag->ants_n[i]->index = 1;
		ag->ants_n[i]->room = ag->rooms[vs->start]->name;
		ag->ants_n[i]->at_end = 0;
		i++;
	}
	i = 0;
	while (ag->rooms[i])
	{
		ag->rooms[i]->visit = 0;
		i++;
	}
}

int		main(void)
{
	t_vars	vs;
	t_args	ag;

	ft_bzero(&vs, sizeof(t_vars));
	ft_bzero(&ag, sizeof(t_args));
	ft_datastruct(&vs, &ag);
	if (vs.cntr == 0)
		ft_exit();
	ft_start_end(&vs, &ag);
	ft_ant_names(&vs, &ag);
	ft_paths(&vs, &ag);
	if (!ag.paths[0])
		ft_exit();
	while (ag.rooms[vs.end]->full < vs.ants)
	{
		vs.j = 0;
		ft_antloop(&vs, &ag);
		ft_putstr("\n");
	}
	ft_free_rooms(&ag);
	ft_free_paths(&ag);
	ft_free_ants(&ag);
	return (0);
}
