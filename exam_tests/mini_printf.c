/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 12:17:26 by daarriba          #+#    #+#             */
/*   Updated: 2020/09/24 11:10:12 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

typedef struct	s_flags
{
	int		width;
	char	dot;
	int		precision;
	int		ret;
}				t_flags;

void	ft_clear(t_flags *flags)
{
	flags->width = 0;
	flags->dot = 0;
	flags->precision = 0;
}

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_nbrlen(unsigned int u, unsigned int b)
{
	int		i;

	i = 1;
	while ((u /= b) > 0)
		i++;
	return (i);
}

void	ft_putstr(char *s, t_flags *flags)
{
	int		j;
	int		k;

	j = (ft_strlen(s) < flags->precision || !flags->dot) ? ft_strlen(s) : flags->precision;
	k = (flags->width > j) ? flags->width - j : 0;
	while (k--)
	{
		write(1, " ", 1);
		flags->ret++;
	}
	write(1, s, j);
	flags->ret += j;
}

void	ft_putnbr(int n)
{
	unsigned int	m;
	char			c;

	if (n < 0)
		m = -n;
	else
		m = n;
	if (m >= 10)
		ft_putnbr(m / 10);
	c = m % 10 + '0';
	write(1, &c, 1);
}

void	ft_putnbrx(unsigned int x)
{
	char c;

	if (x >= 16)
		ft_putnbrx(x / 16);
	if (x % 16 < 10)
		c = x % 16 + '0';
	else
		c = (x % 16) % 10 + 'a';
	write(1, &c, 1);
}

void	ft_putd(int n, t_flags *flags)
{
	int		i;
	int		j;
	int		k;

	i = (n < 0) ? ft_nbrlen(-n, 10) : ft_nbrlen(n, 10);
	j = (i < flags->precision && flags->dot) ? flags->precision - i : 0;
	k = (flags->width > j + i) ? flags->width - j - i : 0;
	while (k-- > (n < 0))
	{
		write(1, " ", 1);
		flags->ret++;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		flags->ret++;
	}	
	while (j--)
	{
		write(1, "0", 1);
		flags->ret++;
	}
	ft_putnbr(n);
	flags->ret += i;
}

void	ft_putx(int n, t_flags *flags)
{
	int		i;
	int		j;
	int		k;

	i = ft_nbrlen(n, 16);
	j = (i < flags->precision && flags->dot) ? flags->precision - i : 0;
	k = (flags->width > j + i) ? flags->width - j - i : 0;
	while (k--)
	{
		write(1, " ", 1);
		flags->ret++;
	}
	while (j--)
	{
		write(1, "0", 1);
		flags->ret++;
	}
	ft_putnbrx(n);
	flags->ret += i;
}

int			ft_atoi(const char *str)
{
	int i;
	int r;

	i = 0;
	r = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r *= 10;
		r -= str[i++] - '0';
	}
	return (-r);
}

int ft_printf(const char *text, ...)
{
	va_list ap;
	t_flags flags;
	int i;

	i = 0;
	flags.ret = 0;
	va_start(ap, text);
	while (text[i])
	{
		if (text[i] != '%')
		{
			write(1, &text[i++], 1);
			flags.ret++;
		}
		else
		{
			i++;
			ft_clear(&flags);
			if (text[i] >= '0' && text[i] <= '9')
				flags.width = ft_atoi(&text[i]);
			while (text[i] >= '0' && text[i] <= '9')
				i++;
			if (text[i] == '.')
			{
				flags.dot = 1;
				flags.precision = ft_atoi(&text[++i]);
			}
			while (text[i] >= '0' && text[i] <= '9')
				i++;
			if (text[i] == 's')
				ft_putstr(va_arg(ap, char*), &flags);
			else if (text[i] == 'd')
				ft_putd(va_arg(ap, int), &flags);
			else if (text[i] == 'x')
				ft_putx(va_arg(ap, unsigned int), &flags);
			i++;
		}
	}
	va_end(ap);
	return(flags.ret);
}

int main(void)
{
	ft_printf("%7.3d",13234);
}
