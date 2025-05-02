/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:00:10 by arphueng          #+#    #+#             */
/*   Updated: 2024/09/04 13:54:48 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_striteri(char const *s, void (*f)(unsigned int, char*))
{
	int		i;
	char	*tmp;

	tmp = (char *)s;
	i = -1;
	if (!tmp)
		return (0);
	while (tmp[++i])
		f(i, &tmp[i]);
	return (0);
}
