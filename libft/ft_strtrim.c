/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:03:47 by sangchpa          #+#    #+#             */
/*   Updated: 2021/01/10 21:22:33 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	s1_len;

	if (s1 == 0)
		return (0);
	if (set == 0)
		return (ft_strdup(s1));
	while (*s1 && ft_strchr(set, *s1) != 0)
		s1++;
	s1_len = ft_strlen(s1);
	while (s1_len && s1[s1_len - 1] && ft_strchr(set, s1[s1_len - 1]) != 0)
		s1_len--;
	p = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (p == 0)
		return (0);
	ft_strlcpy(p, s1, (s1_len + 1));
	return (p);
}
