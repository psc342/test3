#include "ft_printf.h"

int hexlen(unsigned int a)
{
	int len;

	len = 1;
	while(a >= 16)
	{
		a = a / 16;
		len++;
	}

	return len;
}

int itohex(unsigned int a , char x)
{
	char *set;
	if (x == 'x')
		set = "0123456789abcdef";
	else if (x == 'X')
		set = "0123456789ABCDEF";

	char tmp;
	int print_size;

	print_size = hexlen(a);
	
	while (a >= 16)
	{
		if (a >= 16)
		{
			itohex(a/16, x);
			a = a%16;
		}
		else
		{
			tmp = set[a / 16];
			write(1, &tmp, 1);
		}
	}
	write(1, &set[a], 1);

	return print_size;
}

int print_x(unsigned int d, options *opt_list)
{
    int print_size;
	
	if (opt_list->zero == 1 && opt_list->dot == 1)
		opt_list->zero = 0;
	if (opt_list->minus == 1 && opt_list->zero == 1)
		opt_list->zero = 0;
    print_size = print_x_minus(d, opt_list);

    return (print_size);
}

int print_x_minus(unsigned int d, options *opt_list)
{
    int print_size;
    int wid_len;

    print_size = 0;
	if (opt_list->dot == 1 && opt_list->precision == 0)
	{
		print_size--;
        wid_len = opt_list->width - opt_list->precision;
        if (opt_list->precision >= hexlen(d) && d < 0)
            wid_len--;
        while(wid_len > 0)
        {
            if (opt_list->zero == 1)
            	print_size = print_size + ft_putchar('0');
			else
				print_size = print_size + ft_putchar(' ');
			wid_len--;
        }
        while ((opt_list->precision - hexlen(d)) > 0)
        {
            print_size = print_size + ft_putchar('0');
            opt_list->precision--;
        }
	}
    else if(opt_list->minus == 0 && (opt_list->dot == 0 || opt_list->precision < 0))
    {
        wid_len = opt_list->width - hexlen(d);
        while(wid_len > 0)
        {
            if (opt_list->zero == 1)
            	print_size = print_size + ft_putchar('0');
			else
				print_size = print_size + ft_putchar(' ');
            wid_len--;
        }
        itohex(d, opt_list->type);
    }
    else if(opt_list->minus == 0 && opt_list->dot == 1 && opt_list->precision >= 0)
    {
        if (opt_list->precision > (int)hexlen(d))
            wid_len = opt_list->width - opt_list->precision;
        else
            wid_len = opt_list->width - hexlen(d);
        if (opt_list->precision >= (int)hexlen(d) && d < 0)
            wid_len--;
        while(wid_len > 0)
        {
            if (opt_list->zero == 1)
            	print_size = print_size + ft_putchar('0');
			else
				print_size = print_size + ft_putchar(' ');
            wid_len--;
        }
        while ((opt_list->precision - hexlen(d)) > 0)
        {
            print_size = print_size + ft_putchar('0');
            opt_list->precision--;
        }
        itohex(d, opt_list->type);
    }


    else if(opt_list->minus == 1 && (opt_list->dot == 0 || opt_list->precision <0))
    {
        wid_len = opt_list->width - hexlen(d);
        itohex(d, opt_list->type);
        while(wid_len > 0)
        {
            if (opt_list->zero == 1)
            	print_size = print_size + ft_putchar('0');
			else
				print_size = print_size + ft_putchar(' ');
            wid_len--;
        }
    }
    else if(opt_list->minus == 1 && opt_list->dot == 1 && opt_list->precision >= 0)
    {
        
        if (opt_list->precision > (int)hexlen(d))
            wid_len = opt_list->width - opt_list->precision;
        else
            wid_len = opt_list->width - hexlen(d);
        if (opt_list->precision >= (int)hexlen(d) && d < 0)
            wid_len--;
        while ((opt_list->precision - hexlen(d)) > 0)
        {
            print_size = print_size + ft_putchar('0');
            opt_list->precision--;
        }
        itohex(d, opt_list->type);
        while(wid_len > 0)
        {
            if (opt_list->zero == 1)
            	print_size = print_size + ft_putchar('0');
			else
				print_size = print_size + ft_putchar(' ');
            wid_len--;
        }
    }
    return(print_size + hexlen(d));
}