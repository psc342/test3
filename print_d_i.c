#include "ft_printf.h"

int print_d_i(int d, options *opt_list)
{
    int print_size;

    print_size = print_d_i_minus(d, opt_list);

    return (print_size);
}

int print_d_i_minus(int d, options *opt_list)
{
    int print_size;
    int wid_len;

    print_size = 0;

    if(opt_list->minus == 0 && (opt_list->dot == 0 || opt_list->precision <0))
    {
        wid_len = opt_list->width - ft_intlen(d);
        while(wid_len > 0)
        {
            print_size = print_size + ft_putchar(' ');
            wid_len--;
        }
        ft_putnbr(d);
    }
    else if(opt_list->minus == 0 && opt_list->dot == 1 && opt_list->precision >= 0)
    {
        if (opt_list->precision > ft_intlen(d))
            wid_len = opt_list->width - opt_list->precision;
        else
            wid_len = opt_list->width - ft_intlen(d);
        if (opt_list->precision >= ft_intlen(d) && d < 0)
            wid_len--;
        while(wid_len)
        {
            print_size = print_size + ft_putchar(' ');
            wid_len--;
        }
         if (d < 0)
        {
            ft_putchar('-');
            print_size++;
            d = d * -1;
        }
        while ((opt_list->precision - ft_intlen(d)) > 0)
        {
            print_size = print_size + ft_putchar('0');
            opt_list->precision--;
        }
        ft_putnbr(d);
    }


    else if(opt_list->minus == 1 && (opt_list->dot == 0 || opt_list->precision <0))
    {
        wid_len = opt_list->width - ft_intlen(d);
        ft_putnbr(d);
        while(wid_len > 0)
        {
            print_size = print_size + ft_putchar(' ');
            wid_len--;
        }
    }
    else if(opt_list->minus == 1 && opt_list->dot == 1 && opt_list->precision >= 0)
    {
        
        if (opt_list->precision > ft_intlen(d))
            wid_len = opt_list->width - opt_list->precision;
        else
            wid_len = opt_list->width - ft_intlen(d);
        if (opt_list->precision >= ft_intlen(d) && d < 0)
            wid_len--;
        if (d < 0)
        {
            ft_putchar('-');
            print_size++;
            d = d * -1;
        }
        while ((opt_list->precision - ft_intlen(d)) > 0)
        {
            print_size = print_size + ft_putchar('0');
            opt_list->precision--;
        }
        ft_putnbr(d);
        while(wid_len)
        {
            print_size = print_size + ft_putchar(' ');
            wid_len--;
        }
    }
    return(print_size + ft_intlen(d));
}