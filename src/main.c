/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:41:53 by arphueng          #+#    #+#             */
/*   Updated: 2025/05/02 17:16:39 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

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
		}
		else if (ac == 2)
		{
			f->c.re = 1; //default setting after
			f->c.im = 1; //default setting after
		}
		else
			ft_exit(ERROR_MSG, EXIT_FAILURE);
	}
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
	draw(&f);
	mlx_loop(f.mlx);
	//delete_fractol();
	return (0);
}
