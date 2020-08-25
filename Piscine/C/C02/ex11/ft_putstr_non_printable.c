/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:49:35 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/13 11:30:31 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_hex_two_digits(char c)
{
	char	d[2];

	d[0] = c / 16;
	if (d[0] > 10)
		d[0] = 'a' + d[0] % 10;
	else
		d[0] = '0' + d[0];
	d[1] = c % 16;
	if (d[1] >= 10)
		d[1] = 'a' + d[1] % 10;
	else
		d[1] = '0' + d[1];
	write(1, &d, 2);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			write(1, "\\", 1);
			ft_hex_two_digits(str[i]);
		}
		else
			write(1, &str[i], 1);
		++i;
	}
}
