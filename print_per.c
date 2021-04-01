#include "ft_printf.h"

int print_per(options *opt_list)
{
    int print_size;

    print_size = 0;
    if(opt_list->minus == 1 && opt_list->type == '%')
        print_size += ft_putchar('%');
    opt_list->width--;
    while (opt_list->width > 0)
    {
        if (opt_list->zero == 1 && opt_list->minus != 1)
            print_size += ft_putchar('0');
        else
            print_size += ft_putchar(' ');
        opt_list->width--;
    }
    if(opt_list->minus == 0 && opt_list->type == '%')
        print_size += ft_putchar('%');
    return (print_size);
}