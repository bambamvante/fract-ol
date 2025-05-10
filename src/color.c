/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baebae <baebae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:46:41 by arphueng          #+#    #+#             */
/*   Updated: 2025/05/10 17:49:23 by baebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

unsigned int	create_color(unsigned int r, unsigned int g, unsigned int b)
{
	unsigned int	a;

	a = 255;
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

int	set_color(t_fractol *f, int iter)
{
	unsigned int	color;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	// double			s;

	// s = (double)iter / f->max_iter;
	if (iter == f->max_iter)
		color = create_color(0, 0, 0);
	else
	{
		r = (iter * 0) % 256;
        g = (iter * 30) % 256;
        b = (iter * 0) % 256;
		// r = (unsigned int)(9 * (1 - s) * s * s * s * 255);
		// g = (unsigned int)(15 * (1 - s) * (1 - s) * s * s * 255);
		// b = (unsigned int)(8.5 * (1 - s) * (1 - s) * (1 - s) * s * 255);
		color = create_color(r, g, b);
	}
	return (color);
}
