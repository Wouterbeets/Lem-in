/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simulate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 17:30:03 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/21 02:56:22 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

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


int	len_bp(t_backpack *backpack)
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

int		all_taken(t_routes *checking)
{
	t_routes	*tmp;
	tmp = checking;

	while (tmp)
	{
		if (tmp->taken == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	add_to_list(t_best_route **start, t_backpack *bp, int len)
{
	t_best_route	*tmp;

	tmp = *start;
	if (tmp->route)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_best_route *)malloc(sizeof(t_best_route));
		tmp->next->route = bp;
		tmp->next->route_len = len;
		tmp->next->next = NULL;
	}
	else
	{
		tmp->route = bp;
		tmp->route_len = len;
		tmp->next = NULL;
	}
}

void	define_len_routes(t_best *best, t_best_route *sort)
{
	t_routes	*checking;
	int			i;
	int			j;
	t_routes	*smallest;

	i = 0;
	j = 9999999;
	checking = best->routes->checking;
	while (checking)
	{
		checking->taken = 0;
		checking = checking->next;
	}
	checking = best->routes->checking;
	while (checking && !all_taken(checking))
	{
		while (checking)
		{
			i = len_bp(checking->route);
			if (i < j && checking->taken == 0)
			{
				if (smallest)
					smallest->taken = 0;
				j = i;
				smallest = checking;
				smallest->taken = 1;
			}
			checking = checking->next;
		}
		checking = best->routes->checking;
		add_to_list(&sort, smallest->route, j);
		smallest = NULL;
		j = 9999999;
	}
}

void	init_sort(t_best_route **sort)
{
	(*sort) = (t_best_route *)malloc(sizeof(t_best_route));
	(*sort)->next = NULL;
	(*sort)->route = NULL;
	(*sort)->route_len = 0;
}

void	ft_simulate(t_room **rooms, t_best *best)
{
	t_best_route	*sort;
	t_lemmin		*lemmin;
	t_room			*start;

	start = find_start(rooms);
	sort = NULL;
	init_sort(&sort);
	define_len_routes(best, sort);
	lemmin = ft_create_lemmins(&start);
	ft_move_lemmins(rooms, sort, lemmin);
}
