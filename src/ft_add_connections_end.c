/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_connections_end.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 12:21:55 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/13 10:54:38 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "header.h"
#include <stdlib.h>

static t_connect	*new_connection(t_room *new)
{
	t_connect	*new_con;

	new_con = (t_connect *)malloc(sizeof(t_connect));
	new_con->next = NULL;
	new_con->room = new;
	return (new_con);
}

void	ft_add_connections_end(t_connect **start, t_room *new)
{
	t_connect	*tmp;

	if (*start == NULL || (*start)->room == NULL)
	{
		*start = new_connection(new);
	}
	else
	{
		tmp = *start;
		while (tmp->next)
		{
			if (ft_strcmp(tmp->room->id, new->id) == 0)
				return ;
			tmp = tmp->next;
		}
		if (ft_strcmp(tmp->room->id, new->id) == 0)
			return ;
		tmp->next = new_connection(new);
	}
}
