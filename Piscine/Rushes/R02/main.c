/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 09:11:00 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/23 20:25:28 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int			main(int argc, char **argv)
{
	char	*d;

	if (argc == 2)
		ft_write_nbr(argv[1], "numbers.dict");
	else if (argc == 3)
	{
		d = ft_load(argv[1]);
		if (ft_str_is_printable(d))
			ft_write_nbr(argv[2], argv[1]);
	}
	else
		write(1, "Error\n", 6);
}
