/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reduc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 13:40:50 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/16 14:59:48 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_belongs(int i, int *a)
{
	int j;

	j = 0;
	while (j < 4)
	{
		if (a[j] == i)
			return (1);
		j++;
	}
	return (0);
}

int		*ft_intersect(int *a, int *b, int *c)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i <= 4)
	{
		if (ft_belongs(i, a) && ft_belongs(i, b))
		{
			c[j] = i;
			j++;
		}
		i++;
	}
	return (c);
}

int		*ft_reduc(int *a, int *d, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		if (!ft_belongs(d[i], a))
		{
			a[j] = d[i];
			j++;
		}
		i++;
	}
	return (a);
}
