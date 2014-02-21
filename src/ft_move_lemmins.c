/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_lemmins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 19:53:57 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/21 03:16:59 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include "libft.h"

static t_room	*find_start(t_room **room)
{
	t_room	*tmp;

	tmp = *room;
	while (tmp)
	{
		if (tmp->is_start)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}


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

static char		*get_r_n(t_backpack *route, int moves)
{
	t_backpack	*tmp;

	tmp = route;
	while (tmp && moves)
	{
		moves--;
		tmp = tmp->next;
	}
	return (tmp->id);
}

static t_room	*find_room(char *name, t_room **rooms)
{
	t_room	*tmp;

	tmp = *rooms;
	while (tmp)
	{
		if (ft_strcmp(tmp->id, name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

static void	mv_start(t_lemmin *first_lem,t_best_route *best, t_room **rooms)
{
	t_lemmin		*lem;
	t_best_route	*routes;
	t_room			*tmp_room;

	routes = best;
	lem = first_lem;
	while (lem && routes)
	{
		if (lem->moves == 0)
		{
			lem->route = routes->route;
			tmp_room = find_room(get_r_n(lem->route, lem->moves + 1), rooms);
			lem->room = tmp_room;
			tmp_room->num_of_lem++;
			ft_putstr(lem->name);
			ft_putstr("-");
			ft_putstr(tmp_room->id);
			ft_putstr(" ");
			tmp_room = find_room(get_r_n(lem->route, lem->moves), rooms);
			tmp_room->num_of_lem--;
			lem->moves++;
			routes = routes->next;
		}
		lem = lem->next;
	}
}

static void	mv_play(t_lemmin *first_lem, t_best_route *best, t_room **rooms)
{
	t_lemmin	*lem;
	t_room		*tmp_room;

	(void)best;
	lem = first_lem;
	while (lem)
	{
		if (lem->moves && !lem->room->is_end)
		{
			tmp_room = find_room(get_r_n(lem->route, lem->moves + 1), rooms);
			lem->room = tmp_room;
			tmp_room->num_of_lem++;
			ft_putstr(lem->name);
			ft_putstr("-");
			ft_putstr(tmp_room->id);
			ft_putstr(" ");
			tmp_room = find_room(get_r_n(lem->route, lem->moves), rooms);
			tmp_room->num_of_lem--;
			lem->moves++;
		}
		lem = lem->next;
	}
}

void	ft_move_lemmins(t_room **rooms, t_best_route *best, t_lemmin *lemmin)
{
	int				tot_lem;
	t_room			*end;
	t_room			*start;
	t_lemmin		*first_lem;
	t_best_route	*best_start;

	best_start = best;
	end = find_end(rooms);
	start = find_start(rooms);
	first_lem = lemmin;
	tot_lem = start->num_of_lem;
	mv_start(first_lem, best, rooms);
	ft_putstr("\n");
	while (end->num_of_lem < tot_lem)
	{
		mv_play(first_lem, best, rooms);
		mv_start(first_lem, best, rooms);
		ft_putstr("\n");
	}
}
