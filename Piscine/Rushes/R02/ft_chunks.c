/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:16:31 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/23 20:25:32 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

t_chunk		*ft_chunks(char *s)
{
	int			i;
	int			j;
	int			k;
	t_chunk		*c;

	j = ft_strlen(s);
	c = malloc(16 * (j / 3));
	if (c == NULL)
		exit(0);
	k = 0;
	while (k < j / 3)
	{
		c[k].t = (char *)malloc(3);
		if (c[k].t == NULL)
			exit(0);
		i = 0;
		while (i < 3)
		{
			c[k].t[i] = s[i + k * 3];
			i++;
		}
		c[k].u = j - 3 * (k + 1);
		k++;
	}
	return (c);
}

int			ft_put_prefix(char *s, char *d)
{
	char	*v;
	int		i;
	int		k;

	i = 0;
	k = ft_strlen(s);
	v = malloc(k % 3);
	if (v == NULL)
		exit(0);
	while (i < k % 3)
	{
		v[i] = s[i];
		i++;
	}
	ft_put_chunk(v, d);
	free(v);
	if (k % 3 && s[0] != '0')
		ft_powstr(3 * (k / 3), d);
	return (i);
}
