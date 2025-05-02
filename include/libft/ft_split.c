/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 02:43:15 by arphueng          #+#    #+#             */
/*   Updated: 2025/04/17 18:31:33 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char *s, char c)
{
	size_t	count;
	size_t	i;
	int		swtch;

	i = 0;
	count = 0;
	swtch = 0;
	while (*(s + i))
	{
		if (*(s + i) == c)
			swtch = 0;
		else if (swtch == 0)
		{
			swtch++;
			count++;
		}
		i++;
	}
	return (count);
}

static char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (dest == NULL || src == NULL)
		return (NULL);
	while (len > 0 && *(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
		len--;
	}
	*(dest + i) = '\0';
	return (dest);
}

static char	**freealloc(char **alloc)
{
	size_t	i;

	i = 0;
	while (*(alloc + i) != NULL)
	{
		free(*(alloc + i));
		i++;
	}
	free(alloc);
	return (NULL);
}

static char	**alloc(char **str, char *s, char c, size_t word_count)
{
	size_t	i;
	size_t	start;
	size_t	len;

	i = 0;
	start = 0;
	while (i < word_count)
	{
		while (*(s + start) == c)
			start++;
		len = 0;
		while (*(s +(start + len)) && *(s +(start + len)) != c)
			len++;
		*(str + i) = (char *)malloc(sizeof(char) * (len + 1));
		if (*(str + i) == NULL)
			return (freealloc(str));
		ft_strncpy(*(str + i), s + start, len);
		start += len;
		i++;
	}
	*(str + i) = NULL;
	return (str);
}

char	**ft_split(const char *s, char c)
{
	size_t	count;
	char	**str;

	if (!s)
		return (NULL);
	count = count_word((char *)s, c);
	str = (char **)malloc(sizeof(char *) * (count + 1));
	if (str == NULL)
		return (NULL);
	str = alloc(str, (char *)s, c, count);
	return (str);
}
