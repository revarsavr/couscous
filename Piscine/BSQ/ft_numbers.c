/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:11:41 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/25 17:25:34 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_linelen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\n')
		i++;
	return (i);
}

int		ft_str_is_numeric(char *str, int j)
{
	int i;

	i = 0;
	while (str[i] != '\0' && i < j)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		++i;
	}
	return (1);
}

int		ft_atoi(char *str, int j)
{
	int i;
	int r;

	i = 0;
	r = 0;
	while (i < j)
	{
		r *= 10;
		r += str[i++] - '0';
	}
	return (r);
}
