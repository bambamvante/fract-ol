/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:22:19 by arphueng          #+#    #+#             */
/*   Updated: 2025/05/08 16:12:34 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

bool	ft_isfloat_utils(char *nbr, bool digit_found, bool dot_found, int i)
{
	while (nbr[i] == ' ' || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	if (nbr[i] == '+' || nbr[i] == '-')
		i++;
	while (nbr[i])
	{
		if (ft_isdigit(nbr[i]))
			digit_found = true;
		else if (nbr[i] == '.')
		{
			if (dot_found)
				return (false);
			dot_found = true;
		}
		else
			break ;
		i++;
	}
	if (!digit_found)
		return (false);
	while (nbr[i] == ' ' || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	if (nbr[i] != '\0')
		return (false);
	return (true);
}

bool	ft_isfloat(char *nbr)
{
	int		i;
	bool	dot_found;
	bool	digit_found;

	i = 0;
	dot_found = false;
	digit_found = false;
	return (ft_isfloat_utils(nbr, dot_found, digit_found, i));
}
