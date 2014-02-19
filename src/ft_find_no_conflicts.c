/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_no_conflicts.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 14:15:19 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/19 15:39:47 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include "libft.h"
/*
static void		print_bp(t_backpack *bp)
{
	t_backpack *tmp;

	tmp = bp;
	while (bp)
	{
		ft_putstr(bp->id);
		ft_putstr(", ");
		bp = bp->next;
	}
	ft_putstr("\n");
}
*/
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
			if (!route_new->st_end && !route_old->st_end &&
				ft_strcmp(route_new->id, route_old->id) == 0)
			{
	//			print_bp(route_new);
	//			print_bp(route_old);
	//			ft_putstr("conflict");
	//			ft_putstr(route_new->id);
	//			ft_putstr("\t");
	//			ft_putstr(route_new->id);
	//			ft_putstr("\n");

				return (start_old);
			}
			route_new = route_new->next;
		}
		route_new = start_new;
		route_old = route_old->next;
	}
	return (NULL);
}

static t_routes	*lst_cpy(t_routes **to_copy)
{
	t_routes	*copy;
	t_routes	*copy_start;
	t_routes	*tmp;

	tmp = *to_copy;
	copy = (t_routes *)malloc(sizeof(t_routes));
	copy->route = tmp->route;
	copy->compatable = NULL;
	copy->next = NULL;
	copy->checking = NULL;
	copy_start = copy;
	while (tmp->next)
	{
		copy->next = (t_routes *)malloc(sizeof(t_routes));
		copy->next->route = tmp->next->route;
		copy->next->compatable = NULL;
		copy->next->next = NULL;
		copy->next->checking = NULL;
		tmp = tmp->next;
		copy = copy->next;
	}
	return (copy_start);
}

static void		add_to_route(t_routes **lst, t_routes *new)
{
	t_routes	*tmp;

	tmp = *lst;
	if (*lst)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_routes *)malloc(sizeof(t_routes));
		tmp->next->next = NULL;
		tmp->next->checking = new->checking;
		tmp->next->compatable = new->compatable;
		tmp->next->route = new->route;
	}
	else
	{
		*lst = (t_routes *)malloc(sizeof(t_routes));
		(*lst)->next = NULL;
		(*lst)->checking = new->checking;
		(*lst)->compatable = NULL;
		(*lst)->route = new->route;
	}
}
/*
static void	print(t_routes *lst)
{
	t_routes	*tmp;
	t_backpack	*bp;
	tmp = lst;

	while (tmp)
	{
		bp = tmp->route;
		while (bp)
		{
			ft_putstr(bp->id);
			ft_putstr(", ");
			bp = bp->next;
		}
		ft_putstr("\n");
		if (tmp->compatable)
		{
			ft_putstr("\n\t combo\n");
			print(tmp->compatable);
			ft_putstr("\n\t checking = \n");
			print(tmp->checking);
			ft_putstr("\n\t cccccccombo breaker\n");
		}
		tmp = tmp->next;
	}
}
*/
static t_routes		*conflict(t_routes *check, t_routes **start)
{
	t_routes	*to_check_start;
	t_routes	*to_check;
	t_routes	*tmp;
	t_routes	*copy_check;
	t_routes	*copy_tmp;

	to_check = check->checking;
	to_check_start = to_check;
	tmp = *start;
//	ft_putstr("check = ");
//	print(to_check);
	while (tmp)
	{
		while (to_check && !conflict_route(to_check->route, tmp->route))
			to_check = to_check->next;
		if (to_check == NULL)
		{
			to_check = to_check_start;
			copy_check = lst_cpy(&to_check);
			copy_tmp = lst_cpy(&tmp);
			add_to_route(&copy_check, tmp);
			copy_tmp->checking = copy_check;
//			ft_putstr(" copy_check =\n");
//			print(copy_check);
//			ft_putstr("\ntmp->route =\n");
//			print_bp(tmp->route);
//			ft_putstr("\nrecursion\n");
//			ft_putstr("\n");
			copy_tmp->compatable = conflict(copy_tmp, start);
			copy_tmp->checking = copy_check;
			add_to_route(&check->compatable, copy_tmp);
		}
		to_check = to_check_start;
		tmp = tmp->next;
	}
	return (check->compatable);
}

void	ft_find_no_conflicts(t_routes **start)
{
	t_routes	*tmp;
	tmp = *start;
	while (tmp)
	{
		tmp->checking = (t_routes *)malloc(sizeof(t_routes));
		tmp->checking->next = NULL;
		tmp->checking->route = tmp->route;
		tmp->checking->compatable = NULL;
		tmp->checking->checking = NULL;
		tmp->compatable = NULL;
		tmp = tmp->next;
	}
	tmp = *start;
	while (tmp)
	{
		conflict(tmp, start);
//		ft_putstr("route : ");
//		print_bp(tmp->route);
//		ft_putstr("is compatable with: ");
//		ft_putstr("\n----------------------------------");
//		print(tmp->compatable);
		tmp = tmp->next;
//		ft_putstr("\n");
//		ft_putstr("\n");
//		ft_putstr("\n");
	}
}
