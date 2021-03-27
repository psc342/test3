/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:03:40 by sangchpa          #+#    #+#             */
/*   Updated: 2021/01/06 11:53:06 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t nd_len;

	if (*needle == '\0')
		return ((char *)haystack);
	nd_len = ft_strlen(needle);
	while (*haystack != '\0' && len >= nd_len)
	{
		if (*haystack == *needle && ft_strncmp(haystack, needle, nd_len) == 0)
			return (char*)haystack;
		haystack++;
		len--;
	}
	return (0);
}
