/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 11:43:26 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/20 13:42:25 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*k;

	i = 2;
	while (i < argc)
	{
		k = argv[i];
		j = i++ - 1;
		while (j >= 1 && ft_strcmp(argv[j], k) > 0)
		{
			argv[j + 1] = argv[j];
			--j;
		}
		argv[j + 1] = k;
	}
	j = 1;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i] != '\0')
			write(1, &argv[j][i++], 1);
		write(1, "\n", 1);
		j++;
	}
}
