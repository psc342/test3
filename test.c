#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int a;
	int b;

	a = ft_printf("|%0i|", 10);
	ft_printf("\nft_printf = %d",a);
	printf("\n-------------------------\n");
	b = printf("|%0i|", 10);
	printf("\nprintf = %d",b);
}
