/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:14:19 by arphueng          #+#    #+#             */
/*   Updated: 2024/09/27 20:20:05 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printptr(unsigned long n)
{
	if (n >= 16)
	{
		ft_printptr(n / 16);
		ft_printptr(n % 16);
	}
	else
		ft_putchar(LOWERHEX[n]);
}

int	ft_lenptr(unsigned long n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int	ft_putptr(unsigned long n)
{
	int	i;

	i = ft_lenptr(n);
	if (n == 0)
		return (ft_putstr("(nil)"));
	i += ft_putstr("0x");
	ft_printptr(n);
	return (i);
}
