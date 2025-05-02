/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:10:20 by arphueng          #+#    #+#             */
/*   Updated: 2025/05/02 21:35:14 by arphueng         ###   ########.fr       */
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

	tmp.im = a.im * b.im;
	tmp.re = a.re * b.re;
	return (tmp);
}

t_complex	cartesian_to_complex(t_fractol f, int x, int y)
{
	t_complex	complex;

	complex.re = (f.x - f.window->width / 2.0);
	complex.im = (f.y - f.window->height / 2.0);
}

// void	complex_to_cartesian(t_fractol *f, t_complex c, t_fractol *x, t_fractol *y)
// {
	
// }