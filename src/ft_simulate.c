/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simulate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 17:30:03 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/19 20:29:32 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

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

static int		all_taken(t_routes *checking)
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

static void	add_to_list(t_best_route **start, t_backpack *bp, int len)
{
	t_best_route	*tmp;

	tmp = *start;
	if (tmp)
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
		tmp = (t_best_route *)malloc(sizeof(t_best_route));
		tmp->route = bp;
		tmp->route_len = len;
		tmp->next = NULL;
	}
}

static void	define_len_routes(t_best *best, t_best_route *sort)
{
	t_routes	*checking;
	int			i;
	int			j;
	t_routes	*smallest;

	i = 0;
	j = 0;
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
			}
			checking = checking->next;
		}
		checking = best->routes->checking;
		add_to_list(&sort, smallest->route, j);
	}
}

static void	init_sort(t_best_route **sort)
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

	sort = NULL;
	init_sort(&sort);
	define_len_routes(best, sort);
	ft_create_lemmins(rooms);
	ft_move_lemmins(rooms, sort, lemmin);
}
