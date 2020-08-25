/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:52:15 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/20 10:20:11 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

const	int		g_b = 10;
int				g_board[g_b][g_b];

void	ft_board(void)
{
	int i;
	int j;

	i = 0;
	while (i < g_b)
	{
		j = 0;
		while (j < g_b)
			printf("%c ", g_board[j++][i] + '0');
		printf("\n");
		i++;
	}
}

void	ft_queen(int i, int j)
{
	int		k;
	int		c;

	c = 1;
	if (g_board[i][j] == 33)
		c = -1;
	g_board[i][j] = i + 1;
	if (c == 1)
		g_board[i][j] = 33;
	k = 0;
	while (k < g_b - i)
		g_board[i + k++][j] += c;
	k = 0;
	while (k < g_b - i && k < g_b - j)
	{
		g_board[i + k][j + k] += c;
		k++;
	}
	k = 0;
	while (k < g_b - i && k < j + 1)
	{
		g_board[i + k][j - k] += c;
		k++;
	}
}

void	ft_fill(int i, int j)
{
	int k;

	k = 0;
	if (i < 0)
		printf("No sol.");
	else if (i > g_b - 1)
		ft_board();
	else if (j == g_b)
	{
		while (g_board[i - 1][k] != 33)
			k++;
		ft_queen(i - 1, k);
		ft_fill(i - 1, 0);
	}
	else if (g_board[i][j] == 0)
	{
		ft_queen(i, j);
		ft_fill(i + 1, 0);
	}
	else
		ft_fill(i, j + 1);
}

int		main(void)
{
	int i;
	int j;

	i = 0;
	while (i < g_b)
	{
		j = 0;
		while (j < g_b)
		{
			g_board[i][j] = 0;
			j++;
		}
		i++;
	}
	ft_fill(0, 0);
	ft_board();
}
