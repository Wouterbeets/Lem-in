/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_lemmins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 19:28:43 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/21 03:13:19 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include "libft.h"

static char	*make_name(int num)
{
	char	str[2];
	char	*ret;

	str[0] = 'L';
	str[1] = '\0';
	ret = ft_strjoin(str, ft_itoa(num));
	return (ret);
}

static void init_lemmin(t_lemmin **lemmin, int num, t_room *start)
{
	*lemmin = (t_lemmin *)malloc(sizeof(t_lemmin));
	(*lemmin)->next = NULL;
	(*lemmin)->name = make_name(num);
	(*lemmin)->room = start;
	(*lemmin)->route = NULL;
	(*lemmin)->moves = 0;
}

t_lemmin	*ft_create_lemmins(t_room **rooms)
{
	t_room		*start;
	t_lemmin	*lemmin;
	t_lemmin	*lem_start;
	int			i;

	i = 1;
	start = *rooms;
	init_lemmin(&lemmin, i, start);
	lem_start = lemmin;
	i++;
	while (i <= start->num_of_lem)
	{
		init_lemmin(&lemmin->next, i, start);
		lemmin = lemmin->next;
		i++;
	}
	return (lem_start);
}
