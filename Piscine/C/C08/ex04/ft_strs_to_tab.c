/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:46:34 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/27 18:43:44 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

char				*ft_strdup(char *src)
{
	char	*c;
	int		i;

	i = 0;
	while (src[i] != '\0')
		i++;
	c = (char *)malloc(i);
	if (c == 0)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		c[i] = src[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*s;

	i = 0;
	s = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (s == 0)
		return (0);
	while (i < ac)
	{
		s[i].size = ft_strlen(av[i]);
		s[i].str = av[i];
		s[i].copy = ft_strdup(av[i]);
		i++;
	}
	s[i].str = 0;
	s[i].size = 0;
	s[i].copy = 0;
	return (s);
}
