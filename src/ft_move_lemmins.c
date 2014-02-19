/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_lemmins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 19:53:57 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/19 21:55:48 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include "libft.h"

static t_room	*find_end(t_room **room)
{
	t_room	*tmp;

	tmp = *room;
	while (tmp)
	{
		if (tmp->is_end)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

static void	mv_start(t_lemmin *first_lem,t_best_route *best t_rooms **rooms)
{
	t_lemmin		*lem;
	t_best_route	*routes;
	t_room			tmp_room;

	lem = first_lem;
	while (lem && routes)
	{
		if (lem->moves == NULL)
		{
			lem->route = routes->route;
			tmp_room = find_room(get_room_name(lemmin->route, lemmin->moves + 1));
			lemmin->room = tmp_room;
			tmp_room->num_of_lem++;
			tmp_room = find_room(get_room_name(lemmin->route, (lemmin->moves)));
			tmp_room->num_of_lem--;
			lem->moves++;
			ft_putstr(lem->name);
			ft_putstr("-");
			ft_putstr(tmp_room->id);
			routes = routes->next;
		}
		lem = lem->next;
	}
}

void	ft_move_lemmins(t_room **rooms, t_best_route *best, t_lemmin *lemmin)
{
	int				tot_lem;
	t_room			*end;
	t_lemmin		*first_lem;
	t_best_route	*best_start;

	best_start = best;
	end = find_end(rooms);
	first_lem = lemmin;
	tot_lem = (*rooms)->num_of_lem;
	mv_start(first_lem, lem);
	while (end->num_of_lem < tot_lem)
	{
		move_lem_in_play(first_lem, rooms);
		mv_start(first_lem, rooms);
	}
}

}
			if (lemmin->route = NULL)
				lemmin->route = best->route;
			if ((*rooms)->num_of_lem < best->route_len)
			{
				tmp_room->num_of_lem = 0;
