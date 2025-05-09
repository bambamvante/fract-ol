/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:40:17 by arphueng          #+#    #+#             */
/*   Updated: 2025/05/09 22:24:58 by arphueng         ###   ########.fr       */
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

# define WIDTH 800
# define HEIGHT 800

# define NAME "fract-ol"

# define MANDELBROT 1
# define JULIA 2

# define ZOOM_MIN 0.0001
# define ZOOM_MAX 100000
# define ZOOM_FACTOR 1.3


# define ERROR_MSG "\033[1;35m============================================\033[0m \n \
\033[1;36m      ✦･ﾟ: *✧･ﾟ:* *:･ﾟ✧*:･ﾟ✦\033[0m \n \
\033[1;37m   fract-ol: Choose your fractal!\033[0m \n \
\033[1;36m      ✦･ﾟ: *✧･ﾟ:* *:･ﾟ✧*:･ﾟ✦\033[0m \n \
\033[1;33m ✿ Usage ✿\033[0m  ./fractol mandelbrot \n \
    	     ./fractol julia <real> <imaginary> \n \
\033[1;33m ✿ Examples ✿\033[0m \n \
	    ./fractol mandelbrot \n \
	    ./fractol julia -0.8 0.156 \n \
	    ./fractol julia	(uses default values) \n\n \
\033[1;35m ♡ Available fractals ♡\033[0m \n \
	    - mandelbrot \n \
	    - julia \033[1;91m \n \
   Please try again with a valid input!\033[0m \n \
\033[1;35m============================================\033[0m"

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

	double			xdelta;
	double			ydelta;
	double			zoom;
	double			scale;

	t_complex		c;
	t_complex		z;

	bool			need_to_draw;
	void			(*clear_fractol)(void *);

}	t_fractol;

// init
void			init_fractol(t_fractol *f);
void			init_set(t_fractol *f, char *av);
void			clear_fractol(void *param);

// fractol set
void			draw(t_fractol *f);
void			redraw(void *param);
int				julia(t_fractol *f, t_complex *z, t_complex c);
int				mandelbrot(t_fractol *f, t_complex *z, t_complex c);
int				set_fractol(t_fractol *f, t_complex *z, t_complex *c);

//color
int				set_color(t_fractol *f, int iter);
unsigned int	create_color(unsigned int r, unsigned int g, unsigned int b);

// calculate
t_complex		complex_add(t_complex a, t_complex b);
t_complex		complex_sub(t_complex a, t_complex b);
t_complex		complex_mult(t_complex a, t_complex b);
t_complex		cartesian_to_complex(t_fractol f, int x, int y);

// hook
void			key_handler(mlx_key_data_t key_type, void *param);
void			scroll_handler(double xdelta, double ydelta, void *param);
void			close_handler(void *param);

#endif 