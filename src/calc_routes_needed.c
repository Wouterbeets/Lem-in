/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_routes_needed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 20:36:24 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/18 14:09:26 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>
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

static int	len_list(t_connect *backpack)
{
	t_connect	*copy;
	int			i;

	i = 0;
	copy = backpack;
	while (copy)
	{
		copy = copy->next;
		i++;
	}
	return (i);
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
			start_num = len_list(start->connect);
			end_num = len_list(end->connect);
			if (start_num > end_num)
				end->routes_needed = start_num;
			else
				end->routes_needed = end_num;
			return ;
		}
	}
	ft_putstr("ERROR\n");
	exit (-1);
	exit (0);
}
