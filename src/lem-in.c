/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 17:22:51 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/11 20:46:28 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "header.h"

static void draw_from_start(t_room **start)
{
	t_room		*lem;
	t_connect	backpack;
	t_room		routlist;

	lem = *start;
	while (lem)
	{
		ft_move(lem, backpack);
		lem->connect = lem->connect->next;
	}
}

static void draw_from_end(t_room **end)
{
	
}

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

void	init_routes(t_room **room)
{
	t_room	*start;
	t_room	*end;

	if ((start = find_start(room)))
	{
		draw_from_start(&start);
	}
	else
		ft_putstr("ERROR\n");
}
