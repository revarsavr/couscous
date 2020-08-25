/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 13:31:05 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/16 13:40:22 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		*ft_copy(int *a, int *b)
{
	int i;

	i = 0;
	while (i < 4)
	{
		a[i] = b[i];
		i++;
	}
	return (a);
}

int		ft_check(int d[4])
{
	return (d[0] + d[1] + d[2] + d[3] == 10 && d[0] * d[1] * d[2] * d[3] == 24);
}

void	combo(int *p[24])
{
	int d[5];

	d[4] = 0;
	d[0] = 1;
	while (d[0] <= 4)
	{
		d[1] = 1;
		while (d[1] <= 4)
		{
			d[2] = 1;
			while (d[2] <= 4)
			{
				d[3] = 1;
				while (d[3] <= 4)
				{
					if (ft_check(d))
						ft_copy(p[d[4]++], d);
					d[3]++;
				}
				d[2]++;
			}
			d[1]++;
		}
		d[0]++;
	}
}
