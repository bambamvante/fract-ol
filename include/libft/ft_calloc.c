/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:06:29 by arphueng          #+#    #+#             */
/*   Updated: 2025/04/17 18:38:13 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tmp;

	if ((size >= SIZE_MAX && nmemb >= SIZE_MAX)
		|| ((ssize_t)nmemb && (ssize_t)size < 0)
		|| ((ssize_t)nmemb * (ssize_t)size < 0))
		return (NULL);
	tmp = (char *)malloc(nmemb * size);
	if (tmp)
		ft_bzero(tmp, nmemb * size);
	return (tmp);
}
