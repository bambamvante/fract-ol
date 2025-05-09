/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:32:18 by arphueng          #+#    #+#             */
/*   Updated: 2024/09/27 20:21:34 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_allformat(char c, va_list ap)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		i += ft_putstr(va_arg(ap, char *));
	else if (c == 'p')
		i += ft_putptr(va_arg(ap, unsigned long));
	else if (c == 'd')
		i += ft_putnbr(va_arg(ap, int));
	else if (c == 'i')
		i += ft_putnbr(va_arg(ap, int));
	else if (c == 'u')
		i += ft_putunbr(va_arg(ap, unsigned int));
	else if (c == 'x')
		i += ft_puthex(va_arg(ap, unsigned long), c, 0);
	else if (c == 'X')
		i += ft_puthex(va_arg(ap, unsigned long), c, 0);
	else if (c == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	ap;

	i = 0;
	len = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
			len += ft_allformat(str[++i], ap);
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (len);
}
