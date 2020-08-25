/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:45:40 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/25 19:08:33 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H

# define FT_HEADER_H
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_point
{
	int		x;
	int		y;
	int		size;
}				t_point;

typedef struct	s_map
{
	int		lines;
	int		cols;
	char	empty;
	char	obs;
	char	full;
	char	**chart;
	t_point	*obstacles;
	int		obs_count;
	int		first;
}				t_map;

int				ft_strlen(char *s);
int				ft_linelen(char *s);
int				ft_str_is_numeric(char *str, int j);
int				ft_atoi(char *str, int j);
void			ft_obs_count(t_map *map);
int				ft_list_obstacles(t_map *map);
int				ft_check_square(t_point *point, int side, t_map *map);
void			ft_max_square(t_point *point, t_map *map, int max);
void			ft_find(t_map *map);
int				ft_head_data(char *path, int *i);
int				ft_head(char *path, t_map *map);
int				ft_load_chart(char *path, t_map *map);
int				ft_check_symbol(char c, t_map *map);
int				ft_check_same(t_map *map);
int				ft_chart(t_map *map, char *c);
void			ft_fill(t_point point, t_map *map);
void			ft_show(t_map *map);

#endif
