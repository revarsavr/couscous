/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:36:22 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/13 10:04:45 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < (n - 1) && src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = '\0';
		++i;
	}
	return (dest);
}

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

void	ft_putstr_hex(char *c)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (c[i] != '\0')
	{
		ft_hex_two_digits(c[i]);
		if (!j)
			write(1, " ", 1);
		i++;
		j = (j + 1) % 2;
	}
}

void	ft_putstr_dots(char *d)
{
	int i;

	i = 0;
	while (d[i] != '\0')
	{
		if (d[i] < 32 || d[i] > 126)
			write(1, ".", 1);
		else
			write(1, &d[i], 1);
		++i;
	}
}