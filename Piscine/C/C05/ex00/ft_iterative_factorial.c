/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:37:41 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/13 11:41:56 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int j;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	j = nb;
	while (j-- > 1)
		nb *= j;
	return (nb);
}
