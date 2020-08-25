/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:33:42 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/19 18:27:39 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

int		ft_index(char c, char *d)
{
	int i;

	i = 0;
	while (d[i] != '\0')
	{
		if (d[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_check_base(char *base)
{
	int i;
	int j;

	i = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int p;
	int r;
	int b;

	i = 0;
	p = 0;
	r = 0;
	b = ft_strlen(base);
	if (!ft_check_base(base))
		return (0);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' \
	|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '+' || str[i] == '-')
		p += ft_index(str[i++], "+-");
	while (ft_index(str[i], base) >= 0)
	{
		r *= b;
		r -= ft_index(str[i++], base);
	}
	if (!(p % 2))
		r = -r;
	return (r);
}
