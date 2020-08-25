#include <stdio.h>
#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size);

int 	main(void)
{
	int i;
	int t[10] = {19, 10, 8, -17, -9, 3, 10, 11, -12, 15};

	ft_sort_int_tab(t, 10);
	i = 0;
	printf("{");
	while (i < 10)
	{
		printf("%i", t[i]);
		if (i < 9)
			printf(", ");		
		++i;
	}
	printf("}");
}
