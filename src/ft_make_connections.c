/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_connections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 11:05:51 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/11 18:36:40 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "header.h"
#include "libft.h"

static int	has_char(char **line, char c)
{
	char	*str;
	int		i;

	i = -1;
	str = *line;
	if (str[0] == '#')
		return (0);
	while (str[++i])
	{
		if (str[i] == c)
			return (1);
	}
	return (0);
}

static int	tab_len(char **arr)
{
	int		len;
	len = 0;
	while (arr[len] != '\0')
		len++;
	return(len);
}

static char	**get_tube(char	**line)
{
	char	**tube;

	tube = NULL;
	if ((*line)[0] == '#' && (*line)[1] != '#')
	{
		free(*line);
		if (get_next_line(0, line) < 1 && (!has_char(line, '-')))
			return (NULL);
	}
	tube = ft_strsplit(*line, '-');
	if (tab_len(tube) != 2 || ft_strcmp(tube[0], tube[1]) == 0)
	{
		while (*tube != '\0')
			free(*tube++);
		tube = NULL;
	}
	return (tube);
}

int		ft_make_connections(t_room **room, char **line)
{
	char	**tub;
	t_room	*tmp;
	t_room	*tmp2;

	tmp = *room;
	tmp2 = *room;
	if ((tub = get_tube(line)))
	{
		while (ft_strcmp(tub[0], tmp->id) != 0)
		{
			if((tmp = tmp->next) == NULL)
				return (0);
		}
		while (ft_strcmp(tub[1], tmp2->id) != 0)
		{
			if((tmp2 = tmp2->next) == NULL)
				return (0);
		}
		ft_add_connections_end(&tmp->connect, tmp2);
		ft_add_connections_end(&tmp2->connect, tmp);
		return (1);
	}
	return (0);
}
