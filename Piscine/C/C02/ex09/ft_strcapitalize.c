/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 12:34:18 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/13 11:29:18 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z') && j)
		{
			str[i] = str[i] - 32;
			j = 0;
		}
		else if (str[i] < 65 || (str[i] > 90 && str[i] < 97) || str[i] > 122)
		{
			if (str[i] < 48 || str[i] > 58)
				j = 1;
			else
				j = 0;
		}
		else
			j = 0;
		++i;
	}
	return (str);
}
