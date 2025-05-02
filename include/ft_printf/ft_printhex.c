/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:06:03 by arphueng          #+#    #+#             */
/*   Updated: 2024/09/27 20:26:47 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, const char c, int i)
{
	unsigned int	res;

	if (n >= 16)
	{
		i += ft_puthex(n / 16, c, 0);
	}
	res = n % 16;
	if (c == 'x')
		ft_putchar(LOWERHEX[res]);
	else if (c == 'X')
		ft_putchar(UPPERHEX[res]);
	i++;
	return (i);
}
