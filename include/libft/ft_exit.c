/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 21:55:29 by baebae            #+#    #+#             */
/*   Updated: 2025/04/18 13:15:22 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exit(char *str, bool status)
{
	int	i;

	i = 0;
	if (!str)
		exit(EXIT_SUCCESS);
	if (status == EXIT_SUCCESS)
	{
		while (str[i])
		{
			write(STDOUT_FILENO, &str[i], 1);
			i++;
		}
		write(STDOUT_FILENO, "\n", 1);
		exit(status);
	}
	if (status == EXIT_FAILURE)
	{
		while (str[i])
		{
			write(STDERR_FILENO, &str[i], 1);
			i++;
		}
		write(STDOUT_FILENO, "\n", 1);
		exit(status);
	}
}
