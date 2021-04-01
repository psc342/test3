#include "ft_printf.h"

int print_s(char *s, options *opt_list)
{
    int print_size;
    int s_len;

    print_size = 0;
    if (s == 0)
        s = "(null)";
    s_len = ft_strlen(s);
    if (opt_list->dot == 1 && s_len > opt_list->precision)
	    s_len = opt_list->precision;
    if(opt_list->minus == 1)
        print_size += ft_putstr(s, s_len);
    opt_list->width = opt_list->width - s_len;
    while (opt_list->width > 0)
    {
        if (opt_list->zero == 1 && opt_list->minus != 1)
            print_size += ft_putchar('0');
        else
            print_size += ft_putchar(' ');
        opt_list->width = opt_list->width - 1;
    }
    if(opt_list->minus == 0)
        print_size += ft_putstr(s, s_len);
    return (print_size);
}