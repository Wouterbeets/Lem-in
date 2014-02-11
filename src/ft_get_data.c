/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_get_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 09:19:25 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/11 20:32:16 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"
#include <unistd.h>
#include <stdlib.h>

static t_room	*make_room(char **input, int start_end, int num_of_lem)
{
	t_room	*room;

	room = (t_room *)malloc(sizeof(t_room));
	room->id = input[0];
	room->posx = input[1];
	room->posy = input[2];
	room->next = NULL;
	room->is_start = 0;
	room->is_end = 0;
	room->num_of_lem = 0;
	room->connect = NULL;
	room->backpack.next = NULL;
	room->backpack.room = NULL;
	if (start_end == 1)
	{
		room->is_start = 1;
		room->num_of_lem = num_of_lem;
	}
	else if (start_end == 2)
	{
		room->is_end = 1;
	}
	return (room);
}

static int	has_char(char **line, char c)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	str = *line;
	if (str[0] == '#')
		return (0);
	while (str[++i])
	{
		if (str[i] == c)
			j++;
	}
	return (j);
}

static int	is_num(char *str)
{
	int		i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (!(str[i] <= '9' && str[i] >= '0'))
			return (0);
	}
	return (1);
}

static t_room	*read_input(char **line, int num_of_lem)
{
	char	**input;
	t_room	*room;
	int		start_end;

	start_end = 0;
	if ((*line)[0] == '#' && (*line)[1] != '#')
		return (NULL);
	if (ft_strcmp(*line, "##start") == 0 || ft_strcmp(*line, "##end") == 0)
	{
		if ((*line)[2] == 's')
			start_end = 1;
		else
			start_end = 2;
		free(*line);
		get_next_line(0, line);
	}
	if (has_char(line, ' ') == 2)
	{
		input = ft_strsplit(*line, ' ');
		if (is_num(input[1]) && is_num(input[2]))
		{
			room = make_room(input, start_end, num_of_lem);
			return (room);
		}
	}
	return (NULL);
}

t_room		*ft_get_data(void)
{
	t_room	*room;
	t_room	*start;
	char	*line;
	int		num_of_lem;
	int		ret;

	num_of_lem = 0;
	start = NULL;
	while (get_next_line(0, &line) > 0 && (!has_char(&line, '-')))
	{
		if (has_char(&line, ' ') == 0 && num_of_lem == 0 && is_num(line))
			num_of_lem = ft_atoi(line);
		else if ((room = read_input(&line, num_of_lem)))
			ft_add_to_room_end(&start, room);
		else
			return (start);
		free(line);
	}
	ret = ft_make_connections(&start, &line);
	free(line);
	while (ret && get_next_line(0, &line) > 0 && ft_strcmp(line, "") != 0)
	{
		ret = ft_make_connections(&start, &line);
		free(line);
	}
	return (start);
}
