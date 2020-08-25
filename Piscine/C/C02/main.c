#include <string.h>
#include <stdio.h>

char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int	ft_str_is_alpha(char *str);
char	*ft_strupcase(char *str);
char	*ft_strcapitalize(char *str);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
void	ft_putstr_non_printable(char *str);

int main(void)
{
	char s[11] = "buenosdias";
	char t[11];
	//char u[10] = "orehgeorg";
	//char v[44] = "hola +que+tal (como 42estas --yo ESTOy biEn";

	strncpy(t, s, 4);
	printf("%s", t);
}
