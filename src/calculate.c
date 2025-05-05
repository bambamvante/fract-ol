/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:10:20 by arphueng          #+#    #+#             */
/*   Updated: 2025/05/04 23:49:39 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_complex	complex_add(t_complex a, t_complex b)
{
	t_complex	tmp;

	tmp.im = a.im + b.im;
	tmp.re = a.re + b.re;
	return (tmp);
}

t_complex	complex_sub(t_complex a, t_complex b)
{
	t_complex	tmp;

	tmp.im = a.im - b.im;
	tmp.re = a.re - b.re;
	return (tmp);
}

t_complex	complex_mult(t_complex a, t_complex b)
{
	t_complex	tmp;

	tmp.re = a.re * b.re - a.im * b.im;
	tmp.im = a.re * b.im + a.im * b.re;
	return (tmp);
}

t_complex	cartesian_to_complex(t_fractol f, int x, int y)
{
	t_complex	complex;

	complex.re = 0.003 * (x - f.img->width / 2.f);
	complex.im = 0.003 * (y - f.img->height / 2.f);
	return (complex);
}

void	complex_to_cartesian(t_fractol f, t_complex c, int *x, int *y)
{
	*x = c.re + f.img->width / 2.f;
	*y = c.im + f.img->height / 2.f;
}