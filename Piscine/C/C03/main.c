#include <stdio.h>
#include <string.h>
#include "ex04/ft_strstr.c"
int main(void)
{
	char a[] = "";
	char b[] = "a";
	printf("%s\n", strstr(a,b));
	printf("%s\n", ft_strstr(a,b));
}