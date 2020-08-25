/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:11:41 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/26 19:33:35 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_fill(t_point point, t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < point.size)
	{
		j = 0;
		while (j < point.size)
		{
			map->chart[point.x + i][point.y + j] = map->full;
			j++;
		}
		i++;
	}
}

void	ft_show(t_map *map)
{
	int i;

	i = 0;
	while (i < map->lines)
	{
		write(1, map->chart[i], map->cols + 1);
		i++;
	}
}

int		ft_solve(t_map *map, char *arg)
{
	if (ft_head(arg, map) == 0)
		return (0);
	if (ft_load_chart(arg, map) == 0)
		return (0);
	if (ft_list_obstacles(map) == 0)
		return (0);
	ft_find(map);
	ft_show(map);
	return (1);
}

int		ft_inline(t_map *map)
{
	char	buf;
	int		fd;
	int		j;

	fd = open("std_input.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (0);
	while (read(0, &buf, 1))
		write(fd, &buf, 1);
	close(fd);
	write(1, "\n", 1);
	j = ft_solve(map, "std_input.txt");
	return (j);
}

int		main(int argc, char **argv)
{
	t_map	*map;
	int		i;

	i = 1;
	if (argc == 1)
	{
		map = (t_map *)malloc(31);
		if (map == 0)
			return (-1);
		if (ft_inline(map) == 0)
			write(1, "map error", 9);
	}
	else
		while (i < argc)
		{
			map = (t_map *)malloc(31);
			if (map == 0)
				return (-1);
			if (ft_solve(map, argv[i]) == 0)
				write(1, "map error", 9);
			write(1, "\n", 1);
			free(map);
			i++;
		}
	return (0);
}
