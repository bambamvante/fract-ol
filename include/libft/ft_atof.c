/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 00:34:19 by arphueng          #+#    #+#             */
/*   Updated: 2025/05/04 19:42:41 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(char *str)
{
	int		i;
	double	sign;
	double	res;
	double	decimal_apart;
	double	decimal_divisor;

	i = 0;
	sign = 1;
	res = 0.0;
	decimal_apart = 0.0;
	decimal_divisor = 1.0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1.0;
		i++;
	}
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
	return (sign * (res + decimal_apart / decimal_divisor));
}
