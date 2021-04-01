#include "ft_printf.h"

int print_u(unsigned int d, options *opt_list)
{
    int print_size;
	
	if (opt_list->zero == 1 && opt_list->dot == 1)
		opt_list->zero = 0;
	if (opt_list->minus == 1 && opt_list->zero == 1)
		opt_list->zero = 0;
    print_size = print_u_minus(d, opt_list);

    return (print_size);
}

int print_u_minus(unsigned int d, options *opt_list)
{
    int print_size;
    int wid_len;

    print_size = 0;
	if (opt_list->dot == 1 && opt_list->precision == 0)
	{
		print_size--;
        wid_len = opt_list->width - opt_list->precision;
        if (opt_list->precision >= ft_unsignedintlen(d) && d < 0)
            wid_len--;
        while(wid_len > 0)
        {
            if (opt_list->zero == 1)
            	print_size = print_size + ft_putchar('0');
			else
				print_size = print_size + ft_putchar(' ');
			wid_len--;
        }
        while ((opt_list->precision - ft_unsignedintlen(d)) > 0)
        {
            print_size = print_size + ft_putchar('0');
            opt_list->precision--;
        }
	}

    else if(opt_list->minus == 0 && (opt_list->dot == 0 || opt_list->precision < 0))
    {
        wid_len = opt_list->width - ft_unsignedintlen(d);
        while(wid_len > 0)
        {
            if (opt_list->zero == 1)
            	print_size = print_size + ft_putchar('0');
			else
				print_size = print_size + ft_putchar(' ');
            wid_len--;
        }
        ft_putunsigned(d);
    }
    else if(opt_list->minus == 0 && opt_list->dot == 1 && opt_list->precision > 0)
    {
        if (opt_list->precision > (int)ft_unsignedintlen(d))
            wid_len = opt_list->width - opt_list->precision;
        else
            wid_len = opt_list->width - ft_unsignedintlen(d);
        if (opt_list->precision >= (int)ft_unsignedintlen(d) && d < 0)
            wid_len--;
        while(wid_len > 0)
        {
            if (opt_list->zero == 1)
            	print_size = print_size + ft_putchar('0');
			else
				print_size = print_size + ft_putchar(' ');
            wid_len--;
        }
        while ((opt_list->precision - ft_unsignedintlen(d)) > 0)
        {
            print_size = print_size + ft_putchar('0');
            opt_list->precision = opt_list->precision - 1;
        }
        ft_putunsigned(d);
    }

    else if(opt_list->minus == 1 && (opt_list->dot == 0 || opt_list->precision <0))
    {
        wid_len = opt_list->width - ft_unsignedintlen(d);
        ft_putunsigned(d);
        while(wid_len > 0)
        {
            if (opt_list->zero == 1)
            	print_size = print_size + ft_putchar('0');
			else
				print_size = print_size + ft_putchar(' ');
            wid_len--;
        }
    }
    else if(opt_list->minus == 1 && opt_list->dot == 1 && opt_list->precision > 0)
    {
        
        if (opt_list->precision > (int)ft_unsignedintlen(d))
            wid_len = opt_list->width - opt_list->precision;
        else
            wid_len = opt_list->width - ft_unsignedintlen(d);
        if (opt_list->precision >= (int)ft_unsignedintlen(d) && d < 0)
            wid_len--;
        while ((opt_list->precision - ft_unsignedintlen(d)) > 0)
        {
            print_size = print_size + ft_putchar('0');
            opt_list->precision--;
        }
        ft_putunsigned(d);
        while(wid_len > 0)
        {
            if (opt_list->zero == 1)
            	print_size = print_size + ft_putchar('0');
			else
				print_size = print_size + ft_putchar(' ');
            wid_len--;
        }
    }
    return(print_size + ft_unsignedintlen(d));
}