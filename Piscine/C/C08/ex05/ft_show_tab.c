/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:59:46 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/27 18:14:34 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_putnbr(int n)
{
	char			c;
	unsigned int	m;

	if (n < 0)
	{
		c = '-';
		write(1, &c, 1);
		m = -n;
	}
	else
		m = n;
	if (m >= 10)
		ft_putnbr(m / 10);
	c = m % 10 + '0';
	write(1, &c, 1);
}

void	t_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		write(1, &"\n", 1);
		ft_putnbr(par[i].size);
		write(1, &"\n", 1);
		ft_putstr(par[i].copy);
		write(1, &"\n", 1);
		i++;
	}
}
