/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:29:42 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/27 17:33:39 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_strlcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j] != '\0')
		dest[i++] = src[j++];
	dest[i] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*s;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (j < size)
		i += ft_strlen(strs[j++]);
	i += ft_strlen(sep) * (size - 1);
	s = (char *)malloc(i + 1);
	j = 0;
	while (j < size)
	{
		ft_strlcat(s, strs[j]);
		if (j++ < size - 1)
			ft_strlcat(s, sep);
	}
	return (s);
}
