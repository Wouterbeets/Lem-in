/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_routes_needed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 20:36:24 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/11 20:46:00 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>
#include <stdlib.h>

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

void	calc_routes_needed(t_room **room)
{
	t_room	*start;
	t_room	*end;
	int		start_num;
	int		end_num;

	if ((start = find_start(room)))
	{
		if ((end = find_end(room)))
		{
			start_num = num_of_connections(start);
			end_num = num_of_connections(end);
			if (start_num > end_num)
				end->routes_needed = start_num;
			else
				end->routes_needed = end_num;
			return ;
		}
	}
	ft_putstr("ERROR\n");
	exit (0);
}
