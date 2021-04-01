#include "ft_printf.h"

int p_hexlen(unsigned long long a)
{
	int len;

	len = 1;
	while(a >= 16)
	{
		a = a / 16;
		len++;
	}
	len = len + 2;

	return len;
}

int ptohex(unsigned long long a)
{
	char *set = "0123456789abcdef";
	char tmp;
	int print_size;

	print_size = p_hexlen(a);
	while (a >= 16)
	{
		if (a >= 16)
		{
			ptohex(a/16);
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

int print_p(unsigned long long d, options *opt_list)
{
    int print_size;
	if (opt_list->zero == 1 && opt_list->dot == 1)
		opt_list->zero = 0;
	if (opt_list->minus == 1 && opt_list->zero == 1)
		opt_list->zero = 0;

    print_size = print_p_minus(d, opt_list);

    return (print_size);
}

int print_p_minus(unsigned long long d, options *opt_list)
{
    int print_size;
    int wid_len;

    print_size = 0;
	if (opt_list->dot == 1 && opt_list->precision == 0)
	{
		print_size--;
        wid_len = opt_list->width - p_hexlen(d) + 1;
        if (opt_list->precision >= p_hexlen(d) && d < 0)
            wid_len--;
        while(wid_len > 0)
        {
            if (opt_list->zero == 1)
            	print_size = print_size + ft_putchar('0');
			else
				print_size = print_size + ft_putchar(' ');
			wid_len--;
        }
        while ((opt_list->precision - ft_intlen(d)) > 0)
        {
            print_size = print_size + ft_putchar('0');
            opt_list->precision--;
        }
		write(1, "0x", 2);
	}
    else if(opt_list->minus == 0 && (opt_list->dot == 0 || opt_list->precision < 0))
    {
        wid_len = opt_list->width - p_hexlen(d);
        while(wid_len > 0)
        {
            print_size = print_size + ft_putchar(' ');
            wid_len--;
        }
		write(1, "0x", 2);
        ptohex(d);
    }
    else if(opt_list->minus == 0 && opt_list->dot == 1 && opt_list->precision > 0)
    {
        if (opt_list->precision > (int)p_hexlen(d))
            wid_len = opt_list->width - opt_list->precision;
        else
            wid_len = opt_list->width - p_hexlen(d);
        if (opt_list->precision >= (int)p_hexlen(d) && d < 0)
            wid_len--;
		while(wid_len > 0)
        {
            print_size = print_size + ft_putchar(' ');
            wid_len--;
        }
		write(1, "0x", 2);
        while ((opt_list->precision - p_hexlen(d) + 2) > 0)
        {
            print_size = print_size + ft_putchar('0');
            opt_list->precision--;
        }
        ptohex(d);
    }


    else if(opt_list->minus == 1 && (opt_list->dot == 0 || opt_list->precision < 0))
    {
        wid_len = opt_list->width - p_hexlen(d);
		write(1, "0x", 2);
        ptohex(d);
        while(wid_len > 0)
        {
            print_size = print_size + ft_putchar(' ');
            wid_len--;
        }
    }
    else if(opt_list->minus == 1 && opt_list->dot == 1 && opt_list->precision > 0)
    {
        
        if (opt_list->precision > p_hexlen(d))
            wid_len = opt_list->width - opt_list->precision;
        else
            wid_len = opt_list->width - p_hexlen(d);
        if (opt_list->precision >= p_hexlen(d) && d < 0)
            wid_len--;
        while ((opt_list->precision - p_hexlen(d)) > 0)
        {
            print_size = print_size + ft_putchar('0');
            opt_list->precision--;
        }
		write(1, "0x", 2);
        ptohex(d);
        while(wid_len > 0)
        {
            print_size = print_size + ft_putchar(' ');
            wid_len--;
        }
    }
    return(print_size + p_hexlen(d));
}