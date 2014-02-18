/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 19:04:37 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/16 13:10:14 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static void		del_last_item(t_backpack *backpack)
{
	t_backpack	*tmp;

	tmp = backpack;
	while (tmp->next && tmp->next->next)
		tmp = tmp->next;
	if (tmp->next)
	{
		free(tmp->next);
		tmp->next = NULL;
	}
}
/*
static int	len_bp(t_backpack *backpack)
{
	t_backpack	*tmp;
	int			i;

	i = 0;
	tmp = backpack;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
*/
static int		is_in_backpack(char *id, t_backpack *backpack)
{
	t_backpack	*tmp;

	tmp = backpack;
	while (tmp)
	{
		if (ft_strcmp(tmp->id, id) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static void		add_room_to_backpack(t_room *room, t_backpack **backpack)
{
	t_backpack	*tmp;

	tmp = *backpack;
	if (!tmp)
	{
		(*backpack) = (t_backpack *)malloc(sizeof(t_backpack));
		(*backpack)->next = NULL;
		(*backpack)->id = room->id;
		if (room->is_start || room->is_end)
		{
			(*backpack)->st_end = 1;
		}
		else
			(*backpack)->st_end = 0;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_backpack *)malloc(sizeof(t_backpack));
		tmp->next->next = NULL;
		tmp->next->id = room->id;
		if (room->is_start || room->is_end)
			tmp->next->st_end = 1;
		else
			tmp->next->st_end = 0;
	}
}

static t_backpack	*copy_backpack(t_backpack *backpack)
{
	t_backpack	*copy_bp;
	t_backpack	*start;
	t_backpack	*tmp;

	if (backpack)
	{
		tmp = backpack;
		copy_bp = (t_backpack *)malloc(sizeof(t_backpack));
		copy_bp->id = tmp->id;
		copy_bp->st_end = tmp->st_end;
		start = copy_bp;
		while (tmp->next)
		{
			copy_bp->next = (t_backpack *)malloc(sizeof(t_backpack));
			copy_bp->next->id = tmp->next->id;
			copy_bp->next->st_end = tmp->next->st_end;
			copy_bp->next->next = NULL;
			tmp = tmp->next;
			copy_bp = copy_bp->next;
		}
		return (start);
	}
	return (NULL);
}
/*
static t_backpack	*conflict_route(t_backpack *r1, t_backpack *r2)
{
	t_backpack	*start_old;
	t_backpack	*start_new;
	t_backpack	*route_new;
	t_backpack	*route_old;

	route_old = r1;
	route_new = r2;
	start_new = route_new;
	start_old = route_old;
	while(route_old)
	{
		while (route_new)
		{
			if (!route_new->st_end &&
				ft_strcmp(route_new->id, route_old->id) == 0)
				return (start_old);
			route_new = route_new->next;
		}
		route_new = start_new;
		route_old = route_old->next;
	}
	return (NULL);
}
*/
static void		leave_backpack(t_room *room, t_backpack *backpack)
{
	t_backpack	*copy_bp;

	copy_bp = copy_backpack(backpack);
	room->backpack = copy_bp;
}
/*
static int		conflict(t_routes **routes, t_backpack *backpack)
{
	t_routes	*tmp;
	t_backpack	*con;

	tmp = *routes;
	while (tmp)
	{
		if ((con = conflict_route(tmp->route, backpack)))
		{
			if (len_bp(backpack) < len_bp(tmp->route))
				tmp->route = copy_backpack(backpack);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
*/
static void	print_bp(t_backpack *backpack)
{
	t_backpack *tmp;

	tmp = backpack;
	while (tmp)
	{
		ft_putstr(tmp->id);
		ft_putstr(", ");
		tmp = tmp->next;
	}
	ft_putstr("\n ");
}

static void	room_is_end(t_room *room, t_backpack *backpack)
{
	ft_putstr("**********************************************\n");
	ft_putstr("**********************************************\n");
	ft_putstr("**********************************************\n");
	ft_putstr("**********************************************\n");
	ft_putstr("**********************************************\n");
	ft_putstr("in backpack :\n");
	print_bp(backpack);
	ft_putstr("\n");
	t_routes	*tmp;
	t_backpack	*route;

	tmp = room->routes;
	if (room->routes == NULL)
	{
		room->routes = (t_routes *)malloc(sizeof(t_routes));
		room->routes->route = copy_backpack(backpack);
		room->routes->next = NULL;
	}
	else /*if (conflict(&room->routes, backpack) == 0) */
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_routes *)malloc(sizeof(t_routes));
		tmp->next->route = copy_backpack(backpack);
		tmp->next->next = NULL;
	}
	tmp = room->routes;
	route = tmp->route;
	while (tmp)
	{
		while (route->next)
		{
			ft_putstr(route->id);
			ft_putstr(", ");
			route = route->next;
		}
		tmp = tmp->next;
		if (tmp)
		{
			route = tmp->route;
		}
		ft_putstr("\n");
	}
}

void		ft_move_lem(t_room *room, t_backpack *backpack)
{
	ft_putstr("in room : ");
	ft_putstr(room->id);
	ft_putstr("\n");
	leave_backpack(room, backpack);
	add_room_to_backpack(room, &backpack);
	if (room->is_end)
	{
		room_is_end(room, backpack);
		return ;
	}
	else
	{
		room->connect = room->start_connections;
		while (room->connect)
		{
			ft_putstr("trying with room :");
			ft_putstr(room->connect->room->id);
			ft_putstr("\t :");
			ft_putstr("backpack holds \t");
			print_bp(backpack);
			if ((!(is_in_backpack(room->connect->room->id, backpack))))
			{
				ft_putstr("\n :");
				ft_move_lem(room->connect->room, backpack);
				ft_putstr("exited room\n room now = :");
				ft_putstr(room->id);
				ft_putstr("\n");
				ft_putstr("backpack holds \t");
				print_bp(backpack);
				ft_putstr("deleted last item backpack holds \t");
				del_last_item(backpack);
				print_bp(backpack);
				ft_putstr(" \n -------------------\n");
			}
			room->connect = room->connect->next;
		}
	}
}
