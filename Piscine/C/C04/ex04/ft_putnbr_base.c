/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:53:35 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/19 19:38:22 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

int		ft_check_base(char *base)
{
	int i;
	int j;

	i = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char			c;
	unsigned int	i;
	unsigned int	j;

	if (!ft_check_base(base))
		return ;
	i = ft_strlen(base);
	if (nbr < 0)
	{
		c = '-';
		write(1, &c, 1);
		j = -nbr;
	}
	else
		j = nbr;
	if (j >= i)
		ft_putnbr_base(j / i, base);
	c = base[j % i];
	write(1, &c, 1);
}
