/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:14:01 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/23 20:41:17 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void		ft_check_open(int fd)
{
	if (fd == -1)
	{
		write(1, "Dict Error\n", 11);
		exit(0);
	}
}

int			ft_str_is_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
			return (0);
		++i;
	}
	return (1);
}

char		*ft_load(char *path)
{
	int		fd;
	int		i;
	char	*c;

	i = 0;
	fd = open(path, O_RDONLY);
	ft_check_open(fd);
	while (read(fd, &c, 1))
		i++;
	close(fd);
	c = malloc(i);
	if (c == NULL)
		exit(0);
	fd = open(path, O_RDONLY);
	ft_check_open(fd);
	read(fd, c, i);
	close(fd);
	return (c);
}

int			ft_search(char *s, char *path)
{
	char	*d;
	char	*c;
	int		j;

	c = ft_load(path);
	d = ft_strstr(c, s);
	if (d == NULL)
		ft_check_open(-1);
	j = 1;
	while (d[j] != ':')
		j++;
	j++;
	while (d[j] == ' ')
		j++;
	while (d[j] != ' ' && d[j] != '\n')
		write(1, &d[j++], 1);
	write(1, " ", 1);
	free(c);
	return (1);
}
