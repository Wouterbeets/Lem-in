/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_best.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 18:31:28 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/18 20:17:20 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_best	*find_best(t_routes *lst, t_best best, t_best *compare)
{
	t_routes	*tmp;
	t_routes	*tmp_comp;
	t_routes	*tmp_comp_start;


	tmp = lst;
	tmp_comp = tmp->compatable;
	while (tmp)
	{
		while (tmp_comp)
		{
			tmp_comp_start = tmp_comp;
			while (tmp_comp->compatable)
				tmp_comp = tmp_comp->compatable;
			save_info(tmp_comp, compare);
			compare(tmp_comp, best, compare)
			tmp_comp = tmp_comp_start;
			tmp_comp = tmp_comp->next;
		}
		tmp = tmp->next;
	}
}

static void	init_best(t_best *best)
{
	best = (t_best *)malloc(sizeof(t_best));
	best->len_tot = 0;
	best->num_routes = 0;
	best->routes = NULL;
}

t_best		*ft_find_best(t_routes **start)
{
	t_best		*best;
	t_best		*compare;
	t_routes	*tmp;

	tmp = *start;
	init_best(best);
	init_best(compare);
	find_best(tmp, best, compare);
	return (best);
}
