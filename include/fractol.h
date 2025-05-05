/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:40:17 by arphueng          #+#    #+#             */
/*   Updated: 2025/05/05 00:46:17 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../include/ft_printf/ft_printf.h"
# include "../include/libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# include <math.h>
# include <stdbool.h>
# include <stdint.h>

# define WIDTH 1500
# define HEIGHT 800
# define NAME "fract-ol"

# define MANDELBROT 1
# define JULIA 2

# define ERROR_MSG "nifjisjdkifhc"

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_fractol
{
	mlx_t			*mlx;
	mlx_image_t		*img;

	int				x;
	int				y;

	int				set;
	int				max_iter;

	t_complex		c;
	t_complex		z;
	void			(*clear_fractol)(void *);

}	t_fractol;

// init
void		init_fractol(t_fractol *f);
void		init_set(t_fractol *f, char *av);
void		clear_fractol(void *param);

// fractol set
void		draw(t_fractol *f);
int			julia(t_fractol *f, t_complex *z, t_complex c);
int			mandelbrot(t_fractol *f, t_complex *z, t_complex c);
int			set_fractol(t_fractol *f, t_complex *z, t_complex *c);
void		set_color(t_fractol *f, int iter);

// calculate
t_complex	complex_add(t_complex a, t_complex b);
t_complex	complex_sub(t_complex a, t_complex b);
t_complex	complex_mult(t_complex a, t_complex b);
t_complex	cartesian_to_complex(t_fractol f, int x, int y);
void		complex_to_cartesian(t_fractol f, t_complex c, int *x, int *y);

#endif 