/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/10 15:51:48 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/18 19:53:52 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

typedef struct			s_connect
{
	struct s_connect	*next;
	struct s_room		*room;
}						t_connect;

typedef struct		s_backpack
{
	struct s_backpack	*next;
	char				*id;
	int					st_end;
}					t_backpack;

typedef struct		s_routes
{
	struct s_backpack	*route;
	struct s_routes		*next;
	struct s_routes		*compatable;
	struct s_routes		*checking;
}					t_routes;

typedef struct		s_best
{
	int				len_tot;
	struct s_routes	*routes;
	int				num_routes;
}					t_best;

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
	t_connect		*start_connections;
	t_backpack		*backpack;
	int				routes_needed;
	t_routes		*routes;
}					t_room;


t_room	*ft_get_data();
void	ft_add_to_room_end(t_room **start, t_room *new);
void	ft_add_connections_end(t_connect **start, t_room *new);
int		ft_make_connections(t_room **room, char **line);
void	init_routes(t_room **room);
void	calc_routes_needed(t_room **room);
void		ft_move_lem(t_room *room, t_backpack *backpack);
void	ft_find_no_conflicts(t_routes **start);
#endif /* HEADER_H */
