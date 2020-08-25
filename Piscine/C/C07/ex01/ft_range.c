/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:50:27 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/20 20:26:32 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *r;
	int i;

	if (min >= max)
		return (NULL);
	r = (int *)malloc(4 * (max - min));
	i = min;
	while (i < max)
	{
		r[i - min] = i;
		i++;
	}
	return (r);
}
