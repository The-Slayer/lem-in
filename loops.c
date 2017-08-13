/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 13:40:15 by hstander          #+#    #+#             */
/*   Updated: 2017/08/13 17:26:16 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_roomloop(t_vars *vs, t_args *ag)
{
	int		loop_b;

	loop_b = 0;
	while (ag->rooms[vs->k])
	{
		if ((ft_strcmp(ag->paths[vs->i][ag->ants_n[vs->j]->index],
			ag->rooms[vs->k]->name) == 0) &&
				(ft_strcmp(ag->paths[vs->i][ag->ants_n[vs->j]->index - 1],
					ag->ants_n[vs->j]->room) == 0))
		{
			ft_valid(vs, ag, &loop_b);
			if (loop_b == 1)
				break ;
		}
		vs->k++;
	}
}

void	ft_pathloop(t_vars *vs, t_args *ag)
{
	while (ag->paths[vs->i])
	{
		vs->k = 0;
		if (ag->ants_n[vs->j]->index < ft_arrlen(ag->paths[vs->i]))
		{
			ft_roomloop(vs, ag);
		}
		if (vs->move == 1)
		{
			vs->move = 0;
			break ;
		}
		vs->i++;
	}
}

void	ft_antloop(t_vars *vs, t_args *ag)
{
	while (ag->ants_n[vs->j])
	{
		vs->i = 0;
		if (ag->ants_n[vs->j]->at_end != 1)
		{
			ft_pathloop(vs, ag);
		}
		vs->j++;
	}
}

int		ft_digit(t_args *ag)
{
	int	i;

	i = 0;
	while (ag->line[i])
	{
		if (ft_isdigit(ag->line[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
