/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 09:34:38 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/09 12:50:37 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	coords(i,j)
{
	if ((i == 1 || i == y) && j == 1)
		ft_putchar('A');
	else if ((i == 1 || i == y) && j == x)
		ft_putchar('C');
	else if (i == 1 || i == y || j == 1 || j == x)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int i;
	int j;
	if (x > 0 && y > 0)
	{
		i = 1;
		while (i <= y)
		{
			j = 1;
			while (j <= x)
			{
				coords(i,j);
				++j;
			}
			ft_putchar('\n');
			++i;
		}
	}
}
