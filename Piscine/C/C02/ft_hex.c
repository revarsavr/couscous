#include <unistd.h>

void	ft_hex(char c)
{
	char	d;
	char	e;

	if (c >= 16)
		ft_hex(c / 16);
	e = c % 16;
	if (e < 10)
		d = '0' + e;
	else
		d = 'a' + e % 10;
	write(1, &d, 1);
}
