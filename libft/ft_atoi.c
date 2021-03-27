/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 14:46:57 by sangchpa          #+#    #+#             */
/*   Updated: 2021/01/06 19:44:34 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		i;
	int		state;
	long	val;

	i = 0;
	state = 1;
	val = 0;
	while ((str[i] != '\0') && ((9 <= str[i] && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			state = -1;
		i++;
	}
	while ((str[i] != '\0') && ('0' <= str[i] && '9' >= str[i]))
	{
		val = (val * 10) + (str[i] - '0');
		if (val > 2147483647 && state == 1)
			return (-1);
		if (val > 2147483648 && state == -1)
			return (0);
		i++;
	}
	return (state * val);
}
