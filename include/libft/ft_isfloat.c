/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:22:19 by arphueng          #+#    #+#             */
/*   Updated: 2025/04/30 23:50:41 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isfloat(char *nbr)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	if (nbr[i] == '+' || nbr[i] == '-')
		i++;
	while (nbr[i])
	{
		if (nbr[i] == '.')
		{
			if (dot)
				return (false); 
			dot = 1;
		}
		else if (!ft_isdigit(nbr[i]))
			return (false);
		i++;
	}
	if (dot && nbr[i] == '\0')
		return (true);
	return (false);
}