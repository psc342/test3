/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:01:40 by sangchpa          #+#    #+#             */
/*   Updated: 2021/01/10 21:22:51 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_len(int n)
{
	int		len;

	len = 0;
	if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		n = n * -1;
		len++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*p;
	int		n_len;

	n_len = number_len(n);
	if (!(p = malloc(n_len + 1)))
		return (0);
	p[n_len] = '\0';
	if (n == -2147483648)
	{
		p[--n_len] = '8';
		n = n / 10;
	}
	if (n < 0)
	{
		p[0] = '-';
		n = n * -1;
	}
	else if (n == 0)
		p[0] = '0';
	while (n > 0)
	{
		p[--n_len] = '0' + (n % 10);
		n = n / 10;
	}
	return (p);
}
