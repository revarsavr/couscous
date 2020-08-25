/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:01:53 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/26 11:25:31 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int *r;

	if (max <= min)
	{
		*range = 0;
		return (0);
	}
	r = (int *)malloc(8 * (max - min));
	if (r == 0)
		return (-1);
	i = 0;
	while (min < max)
	{
		r[i] = min;
		min++;
		i++;
	}
	*range = r;
	return (i);
}
