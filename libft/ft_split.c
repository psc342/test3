/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:03:07 by sangchpa          #+#    #+#             */
/*   Updated: 2021/01/07 13:16:17 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_str_size(char const *s, char c)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			size++;
		}
		else
			i++;
	}
	return (size);
}

static void		ft_free(char **p, int j)
{
	while (j >= 0)
	{
		free(p[j]);
		j--;
	}
	free(p);
	return ;
}

static char		**ft_line_alloc(char **p, int size, char const *s, char c)
{
	int		i;
	int		j;
	int		len;

	j = 0;
	i = 0;
	while (size > j && s[i])
	{
		len = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			len++;
			i++;
		}
		p[j] = (char *)malloc(sizeof(char) * (len + 1));
		if (p[j] == 0)
			ft_free(p, j);
		j++;
	}
	return (p);
}

static char		**ft_str_alloc(char **p, int size, char const *s, char c)
{
	int		i;
	int		j;
	int		str_len;

	i = 0;
	j = 0;
	while (size > j && s[i])
	{
		str_len = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			str_len++;
			i++;
		}
		ft_strlcpy(p[j++], (s + i - str_len), str_len + 1);
	}
	p[j] = 0;
	return (p);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**p;

	if (s == 0)
		return (0);
	i = 0;
	j = 0;
	p = (char **)malloc(sizeof(char *) * (ft_str_size(s, c) + 1));
	if (p == 0)
		return (0);
	ft_line_alloc(p, ft_str_size(s, c), s, c);
	ft_str_alloc(p, ft_str_size(s, c), s, c);
	return (p);
}
