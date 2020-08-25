/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:12:53 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/20 10:24:12 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int i;

	i = 1;
	if (i > 2147395600)
		return (0);
	while (i * i < nb)
	{
		i++;
		if (i * i == nb)
			return (i);
	}
	return (0);
}