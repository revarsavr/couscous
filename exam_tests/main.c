#include "mini_gnl.c"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd = open("test.txt", 644, O_RDONLY);
	char *str;

	while (get_next_line(&str, fd) > 0)
	{
		printf("%s\n", str);
		free(str);
	}
	system("leaks a.out");
}