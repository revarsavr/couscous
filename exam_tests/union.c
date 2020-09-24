/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 12:20:51 by daarriba          #+#    #+#             */
/*   Updated: 2020/09/24 10:42:49 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	_Bool	c[128] = {0};
	int		i;
	int		j = 0;

	while (++j < 3 && (i = -1) && (argc == 3))
		while (argv[j][++i])
			write(1, &argv[j][i], c[(int)argv[j][i] * (c[(int)argv[j][i]] == 0)] = (c[(int)argv[j][i]] == 0));
	write(1, "\n", 1);
}
