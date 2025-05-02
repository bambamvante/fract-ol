/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix_2D.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:35:15 by baebae            #+#    #+#             */
/*   Updated: 2025/04/10 02:29:50 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_matrix_2d(void **matrix)
{
	int	idx;

	idx = 0;
	if (!matrix)
		return ;
	while (matrix[idx])
		free(matrix[idx++]);
	free(matrix);
}
