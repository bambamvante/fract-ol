/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:46:41 by arphueng          #+#    #+#             */
/*   Updated: 2025/05/09 20:23:24 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

unsigned int	create_color(unsigned int r, unsigned int g, unsigned int b)
{
	unsigned int	alpha;

	alpha = 0xff;
	return ((r << 24) | (g << 16) | (b << 8) | alpha);
}

int	set_color(t_fractol *f, int iter)
{
	unsigned int	color;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	double			scale;

	scale = 1.0 - (double)iter / f->max_iter;
	if (iter == f->max_iter)
		color = create_color(0, 0, 0);
	else
	{
		r = (unsigned int)((iter * 100) * scale) % 256;
		g = (unsigned int)((iter * 10) * scale) % 256;
		b = (unsigned int)((iter * 255) * scale) % 256;
		color = create_color(r, g, b);
	}
	return (color);
}
