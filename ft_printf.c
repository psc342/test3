#include <stdio.h>
#include "ft_printf.h"

int					print2(va_list ap, options *opt_list)
{
	int print_size;

	print_size = 0;
	if (opt_list->type == 'c' || opt_list->type == '%')
		print_size = print_c(va_arg(ap, int), opt_list);
	else if (opt_list->type == 's')
		print_size = print_s(va_arg(ap, char *), opt_list);
	else if (opt_list->type == 'd' || opt_list->type == 'i')
		print_size = print_d_i(va_arg(ap, int), opt_list);
	else if (opt_list->type == 'u')
		print_size = print_u(va_arg(ap, unsigned int), opt_list);
	else if (opt_list->type == 'x' || opt_list->type == 'X')
		print_size = print_x(va_arg(ap, unsigned int), opt_list);
	else if (opt_list->type == 'p')
		print_size = print_p(va_arg(ap, unsigned long long), opt_list);
	return (print_size);
}


void wid_and_pre(va_list ap, int i, char *format, options *opt_list)
{
	if (ft_isdigit(format[i]))
	{
		if (opt_list->dot == 0)
			opt_list->width = opt_list->width * 10 + (format[i] - '0');
		else
			opt_list->precision = opt_list->precision * 10 + (format[i] - '0');
	}
	else
	{
		if (opt_list->dot == 0)
		{
			opt_list->width = va_arg(ap, int);
			if (opt_list->width < 0)
			{
				opt_list->minus = 1;
				opt_list->width = opt_list->width * -1;
			}
		}
		else
			opt_list->precision = va_arg(ap, int);
	}
}


int parsing(va_list ap, int i, char *format, options *opt_list)
{
	i++;
	while (format[i] != '\0' && ft_strchr("dsciupxX%", format[i]) == 0)
	{
		if (format[i] == '0' && opt_list->width == 0 && opt_list->dot == 0)
			opt_list->zero = 1;
		else if (format[i] == '-')
			opt_list->minus = 1;
		else if (format[i] == '.')
			opt_list->dot = 1;
		else if (ft_isdigit(format[i]) || format[i] == '*')
			wid_and_pre(ap, i, format, opt_list);
		i++;
	}
	opt_list->type = format[i];

	return (i);
}


int printf1(va_list ap, char *format)
{
	int i;
	int print_size;
	options opt_list;

	i = 0;
	print_size = 0;
	while(format[i] != '\0')
	{
		if(format[i] == '%')
		{
			opt_init(&opt_list);
			i = parsing(ap, i, format, &opt_list);
			print_size += print2(ap, &opt_list);
		}
		else
			print_size += ft_putchar(format[i]);
		i++;
	}
	return (print_size);
}

int ft_printf(const char *format, ...)
{
	va_list ap;
	int print_size;

	va_start(ap, format);
	print_size = printf1(ap, (char *)format);
	va_end(ap);

	return (print_size);
}



// int main()
// {
// 	int a;
// 	int b;
// 	int c;
// 	c = 10;

// 	a = ft_printf("d=|%-10p|", -1);
// 	printf("\na = %d",a);
// 	printf("\n---------------\n");
// 	b = printf("d=|%-10p|", -1);
// 	printf("\nb = %d",b);	
// }