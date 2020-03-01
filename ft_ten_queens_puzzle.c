#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int     g_size = 10;

void	ft_show(int **b)
{
	int	i;
	int	j;
	char	c;

	i = 0;
	while (i < g_size)
	{
		j = 0;
		while (j < g_size)
		{
			if (b[i][j] == 1)
			{
				c = '0' + j;
				write(1, &c, 1);
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}

void	ft_put_queen(int **b, int i, int j)
{
	int	p;
	int	k;

	p = (b[i][j] == 0) ? -1 : 1;
	k = 0;
	while (k < g_size)
	{
		b[i][k] += p;
		b[k][j] += p;
		if (k <= i && k <= j)
			b[i - k][j - k] += p;
		if (k < g_size - i && k < g_size - j)
			b[i + k][j + k] += p;
		if (k <= i && k < g_size - j)
			b[i - k][j + k] += p;
		if (k < g_size - i && k <= j)
			b[i + k][j - k] += p;
		k++;
	}
	b[i][j] = (p == 1) ? 0 : 1;
}

void	ft_solve(int **b, int *n, int i)
{
	int	j;

	if (i == g_size)
	{
		(*n)++;
		ft_show(b);
	}
	else
	{
                j = 0;
		while (j < g_size)
		{
			if (b[i][j] == 0)
			{
				ft_put_queen(b, i, j);
				ft_solve(b, n, i + 1);
				ft_put_queen(b, i, j);
			}
			j++;
		}
	}
}

int		main(void)
{
	int		i;
	int		**b;

        b = (int **)malloc(sizeof(int *) * g_size);
	i = 0;
	while (i < g_size)
	{
		b[i] = (int *)malloc(sizeof(int) * g_size);
		i++;
	}
	i = 0;
	ft_solve(b, &i, 0);
	return (0);
}

