/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:10:20 by arphueng          #+#    #+#             */
/*   Updated: 2025/05/08 01:23:48 by arphueng         ###   ########.fr       */
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

	complex.re = ((x - WIDTH / 2.0) / (f.scale * f.zoom)) + f.xdelta;
	complex.im = ((y - HEIGHT / 2.0) / (f.scale * f.zoom)) + f.ydelta;
	return (complex);
}
