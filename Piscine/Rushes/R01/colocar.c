#include <stdio.h>
#include <stdlib.h>

int g_cab[16] = {4, 3, 2, 1, 1, 2, 2, 2, 4, 3, 2, 1, 1, 2, 2, 2};

int		*posibles(int i, int *c, int *v, int *h);
int		ft_rep(int *m, int i);
int 	siguiente(int i, int *c);

void 	tablero(int *m)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%i ", m[j + 4 * i]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void colocar(int i, int *m)
{
	int *c;
	int v[2] = {g_cab[i % 4], g_cab[(i % 4) + 4]};
	int h[2] = {g_cab[i / 4 + 8], g_cab[(i / 4) + 12]};
	c = malloc(16);
	if (i < 0)
		printf("Error\n");
	else if (i > 15)
		tablero(m);
	else
	{
		c = posibles(i, c, v, h);
		m[i] = siguiente(m[i], c);
		if (m[i] == 0)
			colocar(i - 1, m);
		else if (ft_rep(m, i) == 0)
			colocar(i, m);
		else
			colocar(i + 1, m);
	}
}

int main(void)
{
	int m[16] = { 0 };
	colocar(0, m);
}