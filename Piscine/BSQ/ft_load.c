/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:11:41 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/25 18:05:42 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int		ft_head_data(char *path, int *i)
{
	int		fg;
	char	*c;

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	fg = open(path, O_RDONLY);
	c = (char *)malloc(1);
	if (c == 0 || fg == -1)
		return (0);
	while (read(fg, c, 1))
	{
		if (*c == '\n')
			i[0]++;
		if (i[0] < 1)
			i[1]++;
		if (i[0] == 1)
			i[2]++;
	}
	close(fg);
	free(c);
	return (1);
}

int		ft_head(char *path, t_map *map)
{
	int		fg;
	int		i[3];
	int		k;
	char	*c;

	if (ft_head_data(path, i) == 0)
		return (0);
	fg = open(path, O_RDONLY);
	c = (char *)malloc(i[1]);
	if (c == 0 || fg == -1)
		return (0);
	read(fg, c, i[1]);
	close(fg);
	k = 0;
	map->first = i[1];
	map->empty = c[i[1] - 3];
	map->obs = c[i[1] - 2];
	map->full = c[i[1] - 1];
	if (ft_check_same(map))
		return (0);
	k = (ft_str_is_numeric(c, i[1] - 3)) ? ft_atoi(c, i[1] - 3) : 0;
	map->lines = (i[0] - 1 == k) ? k : 0;
	map->cols = i[2] - 1;
	free(c);
	return (k * map->lines);
}

int		ft_chart(t_map *map, char *c)
{
	int		i[3];

	i[2] = 0;
	map->chart = (char **)malloc(8 * map->lines);
	if (map->chart == 0)
		return (0);
	i[0] = 0;
	while (i[0] < map->lines)
	{
		i[1] = 0;
		map->chart[i[0]] = (char *)malloc(map->cols + 1);
		if (map->chart[i[0]] == 0
		|| ft_linelen(&c[i[1] + i[0] * (map->cols + 1)]) != map->cols)
			return (0);
		while (i[1] < map->cols + 1)
		{
			map->chart[i[0]][i[1]] = c[i[1] + i[0] * (map->cols + 1)];
			if (map->chart[i[0]][i[1]] == map->obs)
				i[2]++;
			i[1]++;
		}
		i[0]++;
	}
	map->obs_count = i[2];
	return (1);
}

int		ft_load_chart(char *path, t_map *map)
{
	char	*f;
	char	*c;
	int		i;
	int		fg;

	fg = open(path, O_RDONLY);
	f = (char *)malloc(map->first + 1);
	if (f == 0 || fg == -1)
		return (0);
	read(fg, f, map->first + 1);
	i = 0;
	while (read(fg, f, 1))
		i++;
	close(fg);
	fg = open(path, O_RDONLY);
	c = (char *)malloc(i);
	if (c == 0 || fg == -1)
		return (0);
	read(fg, f, map->first + 1);
	read(fg, c, i);
	i = ft_chart(map, c);
	free(c);
	close(fg);
	return (i);
}
