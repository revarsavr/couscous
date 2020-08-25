/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:18:47 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/23 20:27:56 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int			ft_check(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int			ft_is_zero(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i++] != '0')
			return (0);
	}
	return (1);
}

void		ft_write_nbr(char *s, char *d)
{
	int		i;
	t_chunk *c;

	if (ft_is_zero(s))
		ft_search("0", d);
	else if (ft_check(s))
	{
		i = ft_put_prefix(s, d);
		c = ft_chunks(&s[i]);
		i = 0;
		while (i < ft_strlen(s) / 3)
		{
			ft_put_chunk(c[i].t, d);
			if (ft_strncmp(c[i].t, "000", 3))
				ft_powstr(c[i].u, d);
			i++;
		}
		free(c);
	}
	else
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	write(1, "\n", 1);
}
