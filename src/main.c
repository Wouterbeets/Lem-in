/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/10 15:51:24 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/11 14:56:02 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"

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

int		main()
{
	t_room		*room;

	room = ft_get_data();
	print_list(&room);
	return (1);
}
