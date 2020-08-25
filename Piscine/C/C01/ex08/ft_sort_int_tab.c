/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:48:47 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/10 18:42:51 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;
	int k;

	i = 1;
	while (i < size)
	{
		k = tab[i];
		j = i - 1;
		while (j >= 0 && tab[j] > k)
		{
			tab[j + 1] = tab[j];
			--j;
		}
		tab[j + 1] = k;
		++i;
	}
}
