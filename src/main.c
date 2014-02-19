/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/10 15:51:24 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/19 15:37:57 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"
#include <unistd.h>

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
void	print_list(t_room **room)
{
	t_room	*tmp;
	t_connect	*tmp_con;

	tmp = *room;
	while (tmp)
	{
		ft_putstr("\n id = ");
		ft_putstr(tmp->id);
		ft_putstr("\n start = ");
		ft_putstr(ft_itoa(tmp->is_start));
		ft_putstr("\n end = ");
		ft_putstr(ft_itoa(tmp->is_end));
		tmp_con = tmp->connect;
		ft_putstr("\n");
		ft_putstr("conected with :");
		while (tmp_con)
		{
			ft_putstr(tmp_con->room->id);
			ft_putstr(", ");
			tmp_con = tmp_con->next;
		}
		ft_putstr("\n");
		tmp = tmp->next;
	}
}
static void	add_starts(t_room **room)
{
	t_room	*tmp;

	tmp = *room;
	while (tmp)
	{
		tmp->start_connections = tmp->connect;
		tmp = tmp->next;
	}
}
int		main()
{
	t_room		*room;
	t_room		*end;
	t_best		*best;

	room = ft_get_data();
	print_list(&room);
	calc_routes_needed(&room);
	add_starts(&room);
	init_routes(&room);
	end = find_end(&room);
	ft_find_no_conflicts(&end->routes);
	best = ft_find_best(&end->routes);
	ft_putstr("num_routes = ");
	ft_putstr(ft_itoa(best->num_routes));
	ft_putstr("len_tot = ");
	ft_putstr(ft_itoa(best->len_tot));
	ft_putstr("\n");
//	simulate(&room);
	return (1);
}
