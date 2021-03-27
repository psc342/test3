/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:02:42 by sangchpa          #+#    #+#             */
/*   Updated: 2021/01/04 17:37:10 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_cp;
	unsigned char	*src_cp;

	dst_cp = (unsigned char *)dst;
	src_cp = (unsigned char *)src;
	if (dst == 0 && src == 0)
		return (0);
	if (dst < src)
	{
		while (len-- > 0)
			*dst_cp++ = *src_cp++;
	}
	else
	{
		dst_cp = dst_cp + len - 1;
		src_cp = src_cp + len - 1;
		while (len-- > 0)
			*dst_cp-- = *src_cp--;
	}
	return (dst);
}
