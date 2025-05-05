/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:40:01 by arphueng          #+#    #+#             */
/*   Updated: 2025/05/04 23:52:38 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mandelbrot(t_fractol *f, t_complex *z, t_complex c)
{
	int	iter;

	iter = 0;
	z->re = 0;
	z->im = 0;
	while (iter < f->max_iter)
	{
		if (z->re * z->re + z->im * z->im > 4)
			break ;
		*z = complex_add(complex_mult(*z, *z), c);
		iter++;
	}
	return (iter);
}

int	julia(t_fractol *f, t_complex *z, t_complex c)
{
	int	iter;

	iter = 0;
	while (iter < f->max_iter)
	{
		if (z->re * z->re + z->im * z->im > 4)
			break ;
		*z = complex_add(complex_mult(*z, *z), c);
		iter++;
	}
	return (iter);
}

int	set_fractol(t_fractol *f, t_complex *z, t_complex *c)
{
	int	iter;

	iter = 0;
	if (f->set == MANDELBROT)
	{
		*c = cartesian_to_complex(*f, f->x, f->y);
		iter = mandelbrot(f, z, *c);
	}
	else if (f->set == JULIA)
	{
		*z = cartesian_to_complex(*f, f->x, f->y);
		iter = julia(f, z, f->c);
	}
	return (iter);
}

void	set_color(t_fractol *f, int iter)
{
	uint32_t	color;
	float		t;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;

	t = (float)iter / f->max_iter;
	if (iter == f->max_iter)
		color = 0x000000ff;
	else
	{
		r = (uint8_t)(9 * (1 - t) * t * t * t * 255);
		g = (uint8_t)(15 * (1 - t) * (1 - t) * t * t * 255);
		b = (uint8_t)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
		color = (r << 24) | (g << 16) | (b << 8) | 0xFF;
	}
	mlx_put_pixel(f->img, f->x, f->y, color);
}

void	draw(t_fractol *f)
{
	int			iter;
	t_complex	z;
	t_complex	c;

	f->x = 0;
	while (f->x < WIDTH)
	{
		f->y = 0;
		while (f->y < HEIGHT)
		{
			iter = set_fractol(f, &z, &c);
			set_color(f, iter);
			f->y++;
		}
		f->x++;
	}
}