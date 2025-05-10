/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baebae <baebae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:41:53 by arphueng          #+#    #+#             */
/*   Updated: 2025/05/10 16:03:36 by baebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	print_help_msg(void)
{
	ft_printf("============================================\n");
	ft_printf("    	 ✦･ﾟ: *✧･ﾟ:**:･ﾟ✧*:･ﾟ✦\n");
	ft_printf("    	  fract-ol: Controls!\n");
	ft_printf("   	 ✦･ﾟ: *✧･ﾟ:**:･ﾟ✧*:･ﾟ✦\n");
	ft_printf(" ✿ Controls ✿\n");
	ft_printf("   Zoom In/Out:    Scroll Mouse Wheel Up/Down\n");
	ft_printf("   Quit:           Press ESC, X\n");
	ft_printf("\n");
	ft_printf(" ♡ Have Fun Exploring Fractals! ♡\n");
	ft_printf("=============================================");
	ft_printf("\n");
}

void	check_arguments(t_fractol *f, int ac, char **av)
{
	if (f->set == JULIA && (ac == 4 || ac == 2))
	{
		if (ac == 4)
		{
			if (!ft_isfloat(av[2]) || !ft_isfloat(av[3]))
				ft_exit(ERROR_MSG, EXIT_FAILURE);
			f->c.re = ft_atof(av[2]);
			f->c.im = ft_atof(av[3]);
			if ((f->c.re >= 2 || f->c.re <= -2)
				|| (f->c.im >= 2 || f->c.im <= -2))
				ft_exit(ERROR_MSG, EXIT_FAILURE);
		}
		else if (ac == 2)
		{
			f->c.re = -0.2842;
			f->c.im = -0.70176;
		}
	}
	else if (f->set == JULIA && !(ac == 2 || ac == 4))
		ft_exit(ERROR_MSG, EXIT_FAILURE);
	else if (f->set == MANDELBROT && ac != 2)
		ft_exit(ERROR_MSG, EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_fractol	f;

	if (ac < 2)
		ft_exit(ERROR_MSG, EXIT_FAILURE);
	init_set(&f, av[1]);
	check_arguments(&f, ac, av);
	init_fractol(&f);
	print_help_msg();
	mlx_loop_hook(f.mlx, redraw, &f);
	mlx_loop(f.mlx);
	f.clear_fractol(&f);
}
