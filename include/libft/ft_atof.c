/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 00:34:19 by arphueng          #+#    #+#             */
/*   Updated: 2025/05/08 02:42:26 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static double	set_integer_and_decimal(char *str, int i)
{
	double	res;
	double	decimal_apart;
	double	decimal_divisor;

	res = 0.0;
	decimal_apart = 0.0;
	decimal_divisor = 1.0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10.0 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			decimal_apart = decimal_apart * 10.0 + (str[i] - '0');
			decimal_divisor *= 10.0;
			i++;
		}
	}
	return (res + decimal_apart / decimal_divisor);
}

double	ft_atof(char *str)
{
	int		i;
	double	sign;
	double	res;

	i = 0;
	sign = 1;
	res = 0.0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1.0;
		i++;
	}
	res = set_integer_and_decimal(str, i);
	return (sign * res);
}
