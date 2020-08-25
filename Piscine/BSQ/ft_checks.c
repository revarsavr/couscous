/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:54:04 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/25 18:24:45 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int		ft_check_symbol(char c, t_map *map)
{
	if (c != map->obs && c != map->empty)
		return (0);
	return (1);
}

int		ft_check_same(t_map *map)
{
	return (map->empty == map->obs
	|| map->empty == map->full
	|| map->obs == map->full
	|| map->empty < 32
	|| map->empty > 127
	|| map->full < 32
	|| map->full > 127
	|| map->obs < 32
	|| map->obs > 127);
}
