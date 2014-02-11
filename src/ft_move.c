/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 19:04:37 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/11 20:54:48 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>

void		*ft_move(t_room *lem, t_connect backpack)
{
	t_room	*room;

	room = lem;
	if (room->is_end)
	{
		if (room->routes_needed)
		{
			lem->backpack = backpack;
			add_room_to_backpack(&room->routes_to_end, lem);
			room->routes_needed--;
		}
		else
			;//check if lem bp is shorter than longest and replace if so
		return ;
	}
	if (room->backpack == NULL || /*(len_list(backpack) < len_list(room->backpack)
	&& !conflict(backpack, room->backpack)*/)
	{
		room->backpack = backpack;
		add_room_to_backpack(backpack, room);
		while (lem)
		{
			ft_move(lem->connect->room, backpack)
			lem->connect = lem->connect->next;
		}
	}
	else
		return ;
}
