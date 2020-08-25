/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 12:21:57 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/16 16:40:43 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_coord(int c[4], int v[2])
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (i < 4)
	{
		if (c[k] < c[i])
		{
			v[0]++;
			k = i;
		}
		i++;
	}
	k = i - 1;
	while (i >= 0)
	{
		if (c[k] < c[i])
		{
			v[1]++;
			k = i;
		}
		i--;
	}
}

int		*ft_cross(int j, int *p[24], int v[2], int d[24])
{
	int i;
	int w[2];

	i = 0;
	while (i < 24)
	{
		w[0] = 1;
		w[1] = 1;
		ft_coord(p[i], w);
		if (w[0] == v[0] && w[1] == v[1])
			d[i] = p[i][j];
		i++;
	}
	return (d);
}
