/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:50:04 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/09 11:43:08 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_two_digits(int nb)
{
	char c[2];

	c[0] = '0' + nb / 10;
	c[1] = '0' + nb % 10;
	write(1, &c, 2);
}

void	ft_print_comb2(void)
{
	int		i[2];
	char	c[2];

	c[0] = ',';
	c[1] = ' ';
	i[0] = 0;
	while (i[0] <= 99)
	{
		i[1] = i[0] + 1;
		while (i[1] <= 99)
		{
			ft_two_digits(i[0]);
			write(1, &c[1], 1);
			ft_two_digits(i[1]);
			if (i[0] != 98)
				write(1, &c, 2);
			++i[1];
		}
		++i[0];
	}
}
