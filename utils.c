#include "ft_printf.h"

int	ft_putchar(char c)
{
	int i;

	i = 0;
	i = i + write(1, &c, 1);
	return i;
}

int	ft_putstr(char *s, int len)
{
	int print_size;
	int i;

	print_size = 0;
	i = 0;
	if (s == 0)
		return 0;
	while (s[i] != '\0' && i < len)
	{
		print_size = print_size + write(1, &s[i], 1);
		i++;
	}

	return print_size;
}

void	ft_putnbr(int n)
{
	char	c;
	
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr(n * -1);	}
	else
	{
		if (n >= 10)
			ft_putnbr(n / 10);
		c = (n % 10) + '0';
		write(1, &c, 1);
	}

	return ;
}

void	ft_putunsigned(unsigned int n)
{
	char	c;
	
	if (n == 4294967295)
		write(1, "4294967295", 10);
	else
	{
		if (n >= 10)
			ft_putunsigned(n / 10);
		c = (n % 10) + '0';
		write(1, &c, 1);
	}

	return ;
}

unsigned int	ft_unsignedintlen(unsigned int n)
{
	unsigned int uint_len;

	uint_len = 1;
	if (n == 4294967295)
		return 1;

	while (n >= 10)
	{
		uint_len++;
		n = n/10;
	}

	return uint_len;
}

int	ft_intlen(int n)
{
	int int_len;

	int_len = 1;
	if (n == -2147483648)
		return 11;
	else if (n < 0)
	{
		int_len++;
		n = n * -1;
	}

	while (n >= 10)
	{
		int_len++;
		n = n/10;
	}

	return int_len;
}

void opt_init(options *opt_list)
{
	opt_list->minus = 0;
	opt_list->zero = 0;
	opt_list->width = 0;
	opt_list->dot = 0;
	opt_list->precision = 0;
	opt_list->type = 0;

	return ;
}