/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:11:41 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/25 17:45:05 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int		ft_list_obstacles(t_map *map)
{
	int		i[3];

	map->obstacles = (t_point *)malloc(12 * map->obs_count);
	if (map->obstacles == 0)
		return (0);
	i[2] = 0;
	i[0] = 0;
	while (i[0] < map->lines)
	{
		i[1] = 0;
		while (i[1] < map->cols)
		{
			if (map->chart[i[0]][i[1]] == map->obs)
			{
				map->obstacles[i[2]].x = i[0];
				map->obstacles[i[2]].y = i[1];
				map->obstacles[i[2]++].size = 0;
			}
			else if (!ft_check_symbol(map->chart[i[0]][i[1]], map))
				return (0);
			i[1]++;
		}
		i[0]++;
	}
	return (1);
}

int		ft_check_square(t_point *point, int side, t_map *map)
{
	int i;

	i = 0;
	if (side == 0)
		return (1);
	if ((point->x + side > map->lines) || (point->y + side > map->cols))
		return (0);
	while (i < map->obs_count)
	{
		if (map->obstacles[i].x >= point->x
		&& map->obstacles[i].y >= point->y
		&& map->obstacles[i].x < point->x + side
		&& map->obstacles[i].y < point->y + side)
			return (0);
		i++;
	}
	return (1);
}

void	ft_max_square(t_point *point, t_map *map, int max)
{
	int k;

	k = 0;
	if (!ft_check_square(point, max + 1, map))
		point->size = k;
	else
		k = max + 1;
	while (ft_check_square(point, k, map))
		k++;
	point->size = k - 1;
}

void	ft_find(t_map *map)
{
	t_point	point;
	t_point p_max;

	p_max.x = 0;
	p_max.y = 0;
	p_max.size = 0;
	point.x = 0;
	while (point.x < map->lines)
	{
		point.y = 0;
		while (point.y < map->cols)
		{
			ft_max_square(&point, map, p_max.size);
			if (point.size > p_max.size)
				p_max = point;
			point.y++;
		}
		point.x++;
	}
	ft_fill(p_max, map);
}
