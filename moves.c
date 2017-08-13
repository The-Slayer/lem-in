/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 13:44:54 by hstander          #+#    #+#             */
/*   Updated: 2017/08/13 13:58:48 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_moveto(t_vars *vs, t_args *ag, int *loop_b)
{
	ag->rooms[vs->k]->full += 1;
	ag->ants_n[vs->j]->room = ag->rooms[vs->k]->name;
	ft_putstr("L");
	ft_putstr(ag->ants_n[vs->j]->name);
	ft_putstr("-");
	ft_putstr(ag->rooms[vs->k]->name);
	ft_putstr(" ");
	vs->move = 1;
	vs->l = 0;
	*loop_b = 1;
}

int		ft_movefrom(t_vars *vs, t_args *ag)
{
	if (ft_strcmp(ag->paths[vs->i][ag->ants_n[vs->j]->index - 1],
		ag->rooms[vs->l]->name) == 0)
	{
		ag->rooms[vs->l]->full -= 1;
		return (1);
	}
	return (0);
}

void	ft_valid(t_vars *vs, t_args *ag, int *loop_b)
{
	if (ag->rooms[vs->k]->full == 0 && ag->rooms[vs->k]->end == 0)
	{
		ft_moveto(vs, ag, loop_b);
		while (ag->rooms[vs->l])
		{
			if (ft_movefrom(vs, ag) == 1)
				break ;
			vs->l++;
		}
		ag->ants_n[vs->j]->index += 1;
	}
	else if (ag->rooms[vs->k]->end == 1)
	{
		ag->ants_n[vs->j]->at_end = 1;
		ft_moveto(vs, ag, loop_b);
		while (ag->rooms[vs->l])
		{
			if (ft_movefrom(vs, ag) == 1)
				break ;
			vs->l++;
		}
		ag->ants_n[vs->j]->index += 1;
	}
}
