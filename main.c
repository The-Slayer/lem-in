/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 09:50:30 by hstander          #+#    #+#             */
/*   Updated: 2017/08/03 14:14:31 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_vars	vs;
	t_args	ag;
	char	*ants_n;
	int		i;
	int		j;
	int		k;
	int	 	start;
	int		end;

	j = 0;
	i = 0;
	k = 0;
	ft_bzero(&vs, sizeof(t_vars));
	ft_bzero(&ag, sizeof(t_args));
	ft_datastruct(&vs, &ag);

	ants_n = (char *)ft_memalloc(sizeof(char) * (vs.ants + 1));
	

	start = 0;
	end = 0;
	while (i < vs.ants)
	{
		ants_n[i] = i + 1 + '0';
		i++;
	}
	i = 0;
	vs.r_i = 0;
	while (ag.rooms[start]->start == 0)
		start++;
	while (ag.rooms[end]->end == 0)
		end++;
	ag.rooms[start]->full = vs.ants;
	while (ag.rooms[end]->full < vs.ants)
	{
		if (ants_n[i] != '\0' && ants_n[i] == 'e')
			i++;
		j = 0;
		while (ag.rooms[start]->room[j])
		{
			if (ag.rooms[start]->room[j]->full == 0)
			{
				if (ag.rooms[start]->room[j]->name == ag.rooms[end]->name)
					ag.rooms[start]->room[j]->full += 1;
				else
					ag.rooms[start]->room[j]->full = 1;
				ag.rooms[start]->room[j]->ant = ants_n[i];
				ants_n[i] = 'e';
				i++;
				printf("-->L%c-%s ", ag.rooms[start]->room[j]->ant, ag.rooms[start]->room[j]->name);
			}
			else if (ag.rooms[start]->room[j]->name == ag.rooms[end]->name)
			{
				ag.rooms[end]->full += 1;
				printf("L%c-%s ", ag.rooms[start]->room[j]->ant, ag.rooms[start]->room[j]->name);
			}
			j++;
		}
		k = 0;
		while (ag.rooms[k])
		{
			if (ag.rooms[k]->full != 0 && (ag.rooms[k]->name != ag.rooms[end]->name || ag.rooms[k]->name != ag.rooms[start]->name))
			{
				j = 0;
				while (ag.rooms[k]->room[j])
				{
					if (ag.rooms[k]->room[j]->full == 0)
					{
						if (ag.rooms[k]->room[j]->name == ag.rooms[end]->name)
							ag.rooms[k]->room[j]->full += 1;
						else
							ag.rooms[k]->room[j]->full = 1;
						ag.rooms[k]->room[j]->ant = ag.rooms[k]->ant;
						ag.rooms[k]->full = 0;
						printf("L%c-%s ", ag.rooms[k]->room[j]->ant, ag.rooms[k]->room[j]->name);
					}
					else if (ag.rooms[k]->room[j]->name == ag.rooms[end]->name)
					{
						ag.rooms[k]->full = 0;
						ag.rooms[end]->full += 1;
						printf("L%c-%s ", ag.rooms[k]->room[j]->ant, ag.rooms[k]->room[j]->name);
					}
					j++;
				}
			}
			k++;
		}
		printf("\n");
/*		else 
		{
			while (ag.rooms[k].name != ag.rooms[start].room[j].name)
			{
				k++;
			}

		}
*/	}
	printf("name = %s full = %d\n", ag.rooms[start]->name, ag.rooms[start]->full);
	
	return (0);
}
