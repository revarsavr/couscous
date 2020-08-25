/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_chunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:15:26 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/23 20:25:35 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void		ft_powstr(int i, char *d)
{
	char	*t;
	int		j;

	if (i == 0)
		return ;
	j = 1;
	t = (char *)malloc(i + 2);
	if (t == NULL)
		exit(0);
	t[0] = '1';
	while (j <= i)
	{
		t[j] = '0';
		j++;
	}
	t[i + 1] = '\0';
	ft_search(t, d);
}

void		ft_write_two(char *s, char *d)
{
	char	*u;

	if (s[0] == '1')
		ft_search(s, d);
	else
	{
		u = malloc(2);
		if (u == NULL)
			exit(0);
		u[0] = s[0];
		u[1] = '0';
		ft_search(u, d);
	}
}

void		ft_put_chunk(char *s, char *d)
{
	int		i;
	char	*u;

	i = ft_strlen(s);
	if (s[0] == '0')
		ft_put_chunk(&s[1], d);
	else if (i == 1)
		ft_search(s, d);
	else if (i == 2)
	{
		ft_write_two(s, d);
		if (s[0] != '1')
			ft_put_chunk(&s[1], d);
	}
	else if (i == 3)
	{
		u = malloc(1);
		if (u == NULL)
			exit(0);
		*u = s[0];
		ft_search(u, d);
		ft_search("100", d);
		ft_put_chunk(&s[1], d);
	}
}
