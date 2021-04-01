#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "./libft/libft.h"


typedef struct	flag
{
	int			minus;
	int			zero;
	int			width;
	int			dot;
	int			precision;
	int			star;
	char		type;
}				options;

int	ft_putchar(char c);
void	ft_putnbr(int n);
int	ft_putstr(char *s, int len);
int processing(char *format, va_list ap, int i);
int	ft_intlen(int n);
void	opt_init(options *opt_list);
int print_d_i(int d, options *opt_list);
int print_d_i_minus(int d, options *opt_list);
int print_c(int c, options *opt_list);
int print_s(char *s, options *opt_list);
int print_u(unsigned int d, options *opt_list);
int print_u_minus(unsigned int d, options *opt_list);
void	ft_putunsigned(unsigned int n);
int	ft_unsignedintlen(unsigned int n);
int hexlen(unsigned int a);
int itohex(unsigned int a , char x);
int print_x(unsigned int d, options *opt_list);
int print_x_minus(unsigned int d, options *opt_list);
int print_p(unsigned long long d, options *opt_list);
int print_p_minus(unsigned long long d, options *opt_list);
int print_per(options *opt_list);
int ft_printf(const char *format, ...);
int printf1(va_list ap, char *format);
int parsing(va_list ap, int i, char *format, options *opt_list);
void wid_and_pre(va_list ap, int i, char *format, options *opt_list);
int	print2(va_list ap, options *opt_list);
#endif