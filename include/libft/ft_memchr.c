/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 23:52:28 by arphueng          #+#    #+#             */
/*   Updated: 2024/09/09 23:46:01 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = (char *)s;
	while (i < n)
	{
		if (tmp[i] == (char)c)
			return (&tmp[i]);
		i++;
	}
	return (NULL);
}
// int	main()
// {
// 	printf("%s\n", (char *) ft_memchr("1232342242422", '2', 1));
// }
