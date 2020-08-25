/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:13:24 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/23 20:25:37 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int			ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int			ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && i < n - 1)
		i++;
	return (s1[i] - s2[i]);
}

char		*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	j = ft_strlen(to_find);
	if (to_find[0] == '\0')
		return (&str[i]);
	while (str[i] != '\0')
	{
		if (!ft_strncmp(&str[i], &to_find[0], j))
			return (&str[i]);
		i++;
	}
	return (NULL);
}
