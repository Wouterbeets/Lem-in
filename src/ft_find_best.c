/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_best.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 18:31:28 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/19 15:30:06 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

static void	compare_best(t_best **best, t_best **compare)
{
	if ((*best)->routes == NULL)
	{
		(*best)->len_tot = (*compare)->len_tot;
		(*best)->num_routes = (*compare)->num_routes;
		(*best)->routes = (*compare)->routes;
	}
	else
	{
		if ((*best)->num_routes <= (*compare)->num_routes)
		{
			if (!(*best)->num_routes == (*compare)->num_routes &&
				(*best)->len_tot < (*compare)->len_tot)
			{
				return;
			}
			else
			{
				(*best)->len_tot = (*compare)->len_tot;
				(*best)->num_routes = (*compare)->num_routes;
				(*best)->routes = (*compare)->routes;
			}
		}
	}
}

static int	count_elem(t_backpack *bp)
{
	t_backpack	*tmp;
	int			i;

	i = 0;
	tmp = bp;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

static void	save_info(t_routes *lst, t_best **compare)
{
	t_routes	*tmp;
	t_routes	*tmp_check;

	(*compare)->num_routes = 0;
	(*compare)->len_tot = 0;
	tmp = lst;
	tmp_check = tmp->checking;
	(*compare)->routes = tmp;
	while (tmp_check)
	{
		(*compare)->num_routes++;
		(*compare)->len_tot += count_elem(tmp_check->route);
		tmp_check = tmp_check->next;
	}
}

static t_best	**find_best(t_routes **lst, t_best **best, t_best **compare)
{
	t_routes	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->compatable)
			best = find_best(&tmp->compatable, best, compare);
		save_info(tmp, compare);
		compare_best(best, compare);
		tmp = tmp->next;
	}
	return (best);
}

static void	init_best(t_best **best)
{
	(*best) = (t_best *)malloc(sizeof(t_best));
	(*best)->len_tot = 0;
	(*best)->num_routes = 0;
	(*best)->routes = NULL;
}

t_best		*ft_find_best(t_routes **start)
{
	t_best		*best;
	t_best		*compare;
	t_routes	*tmp;

	tmp = *start;
	best = NULL;
	compare = NULL;
	init_best(&best);
	init_best(&compare);
	find_best(&tmp, &best, &compare);
	tmp = tmp->next;
	return (best);
}
