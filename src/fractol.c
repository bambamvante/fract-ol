/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:40:01 by arphueng          #+#    #+#             */
/*   Updated: 2025/05/07 12:37:16 by arphueng         ###   ########.fr       */
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

void	draw(t_fractol *f)
{
	int			iter;
	int			color;
	t_complex	z;
	t_complex	c;

	f->x = 0;
	while (f->x < WIDTH)
	{
		f->y = 0;
		while (f->y < HEIGHT)
		{
			iter = set_fractol(f, &z, &c);
			color = set_color(f, iter);
			mlx_put_pixel(f->img, f->x, f->y, color);
			f->y++;
		}
		f->x++;
	}
}
