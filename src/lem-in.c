/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 17:22:51 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/14 09:04:25 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "header.h"
#include "libft.h"

static void draw_from_start(t_room **start)
{
	t_room		*room;
	t_backpack	*backpack;

	backpack = NULL;
	room = *start;
	ft_move_lem(room, backpack);
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

	if ((start = find_start(room)))
	{
		draw_from_start(&start);
	}
	else
		ft_putstr("ERROR\n");
}
