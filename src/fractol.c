/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:40:01 by arphueng          #+#    #+#             */
/*   Updated: 2025/05/02 21:41:26 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mandelbrot(t_fractol *f, t_complex *z, t_complex c)
{
	int	set;

	set = 0;
	z->re = 0;
	z->im = 0;
	while (set < f->max_set)
	{
		//∣z∣2=Re(z)2+Im(z)2
		if (z->re * z->re + z->im * z->im > 4)
			break ;
		// z = z^2 + c
		*z = complex_add(complex_mult(*z, *z), c);
		set++;
	}
	return (set);
}

int	julia(t_fractol *f, t_complex *z, t_complex c)
{
	int	set;

	set = 0;
	while (set < f->max_iter)
	{
		if (z->re * z->re + z->im * z->im > 4)
			break ;
		// z = z^2 + c
		*z = complex_add(complex_mult(*z, *z), c);
		set++;
	}
	return (set);
}

int	set_fractol(t_fractol *f, t_complex *z, t_complex *c)
{
	int	set;

	if (f->set == MANDELBROT)
	{
		*c = cartesian_to_complex(*f, f->x, f->y);
		set = mandelbrot(f, z, c);
	}
	else if (f->set == JULIA)
	{
		*z = cartesian_to_complex(*f, f->x, f->y);
		set = julia(f, z, f->c);
	}
	return (set);
}

void	draw(t_fractol *f)
{
	int			set;
	t_complex	z;
	t_complex	c;

	while (f->x < f->window->width)
	{
		while (f->y < f->window->height)
		{
			set = set_fractol(f, &z, &c);
			f->y++;
		}
		f->x++;
	}
}

