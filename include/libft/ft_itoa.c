/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 02:47:21 by arphueng          #+#    #+#             */
/*   Updated: 2024/09/02 20:37:11 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int num)
{
	char	*res;
	int		len;
	long	n;

	n = num;
	len = ft_intlen(n);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	res[len--] = '\0';
	if (n == 0)
		*res = '0';
	if (n < 0)
	{
		n = -n;
		*res = '-';
	}
	while (n > 0)
	{
		res[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}
