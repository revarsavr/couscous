/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 09:45:17 by daarriba          #+#    #+#             */
/*   Updated: 2020/09/24 11:25:01 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*ft_stradd(char *str, char c)
{
	char	*t;
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (!(t = malloc(i + 2)))
		return (NULL);
	i = -1;
	while (str[++i])
		t[i] = str[i];
	t[i++] = c;
	t[i] = 0;
	free(str);
	return (t);
}

int		get_next_line(char **line, int fd)
{
	char	buf;
	int		i;

	if (!(*line = malloc(1)))
		return (-1);
	*line[0] = 0;
	while ((i = read(fd, &buf, 1)) > 0)
	{
		if (buf == '\n')
			return (1);
		*line = ft_stradd(*line, buf);
	}
	return (i);
}
