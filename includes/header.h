/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/10 15:51:48 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/11 20:30:14 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

typedef struct			s_connect
{
	struct s_connect	*next;
	struct s_room		*room;
}						t_connect;

typedef struct		s_room
{
	struct s_room	*next;
	char			*id;
	char			*posx;
	char			*posy;
	int				is_start;
	int				is_end;
	int				num_of_lem;
	t_connect		*connect;
	t_connect		backpack;
	int				routes_needed;
	struct s_room	*routes_to_end;
}					t_room;


t_room	*ft_get_data();
void	ft_add_to_room_end(t_room **start, t_room *new);
void	ft_add_connections_end(t_connect **start, t_room *new);
int		ft_make_connections(t_room **room, char **line);
void	init_routes(t_room **room);
#endif /* HEADER_H */
