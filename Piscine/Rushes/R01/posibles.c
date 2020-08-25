/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   posibles.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 09:46:56 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/16 16:47:56 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	combo(int *p[24]);
int		*ft_intersect(int *a, int *b, int *c);
int		*ft_reduc(int *a, int *d, int size);
void	ft_coord(int *c, int *v);
int		*ft_cross(int j, int *p[24], int *v, int *d);

int		*posibles(int i, int *c, int *v, int *h)
{
	int a[4] = { 0 };
	int b[4] = { 0 };
	int d[24] = { 0 };
	int e[24] = { 0 };
	int j = 0;
    int *p[24];

    while (j < 24)
	{
    	p[i] = malloc(20);
		j++;
	}
	combo(p);
	ft_reduc(a, ft_cross(i / 4, p, v, d), 24);
	ft_reduc(b, ft_cross(i % 4, p, h, e), 24);
	ft_intersect(a, b, c);
	return (c);
}
