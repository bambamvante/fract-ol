/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:41:36 by arphueng          #+#    #+#             */
/*   Updated: 2025/05/01 18:17:58 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_set(t_fractol *f, char *av)
{
	int	len;

	len = ft_strlen(av);
	if ((ft_strncmp(av, "Mandelbrot", 10) == 0) && len == 10)
		f->set = MANDELBROT;
	else if ((ft_strncmp(av, "Julia", 5) == 0) && len == 5)
		f->set = JULIA;
	else
		ft_exit(ERROR_MSG, EXIT_FAILURE);
}

void	init_fractol(t_fractol *f)
{
	mlx_set_setting(MLX_MAXIMIZED, true);
	f->mlx = mlx_init(WIDTH, HEIGHT, NAME, true);
	f->window = mlx_new_image(f->mlx, f->mlx->width, f->mlx->height);
	f->x = 0;
	f->y = 0;
	f->max_iter = 50;
}

void	delete_fractol(void *param)
{
	t_fractol	*f;

	f = (t_fractol *)(param);
}