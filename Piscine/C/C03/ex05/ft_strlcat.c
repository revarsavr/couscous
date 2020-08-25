/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:50:01 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/19 10:29:41 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = ft_strlen(dest);
	k = ft_strlen(src);
	k += i;
	if (size <= i)
		k += size - i;
	j = 0;
	while (src[j] != '\0' && i + 1 < size)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (k);
}
