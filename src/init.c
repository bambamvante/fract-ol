/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:41:36 by arphueng          #+#    #+#             */
/*   Updated: 2025/05/05 01:05:57 by arphueng         ###   ########.fr       */
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

void	key_handler(mlx_key_data_t key_type, void *param)
{
	if (key_type.key == MLX_KEY_ESCAPE && key_type.action == MLX_PRESS)
		clear_fractol(param);
}

void	close_handler(void *param)
{
	clear_fractol(param);
}

void	init_fractol(t_fractol *f)
{
	mlx_set_setting(MLX_MAXIMIZED, true);
	f->mlx = mlx_init(WIDTH, HEIGHT, NAME, true);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(f->mlx, f->img, 0, 0);
	mlx_key_hook(f->mlx, key_handler, f);
	mlx_close_hook(f->mlx, close_handler, f);
	f->x = 0;
	f->y = 0;
	f->max_iter = 100;
}

void	clear_fractol(void *param)
{
	t_fractol	*f;

	f = (t_fractol *)(param);
	if (f->img)
		mlx_delete_image(f->mlx, f->img);
	if (f->mlx)
		mlx_terminate(f->mlx);
	exit(EXIT_SUCCESS);
}
