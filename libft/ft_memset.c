/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:02:46 by sangchpa          #+#    #+#             */
/*   Updated: 2021/01/06 19:52:26 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*b_cp;
	unsigned char	c_cp;

	b_cp = (unsigned char *)b;
	c_cp = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		b_cp[i] = c_cp;
		i++;
	}
	return (b);
}
