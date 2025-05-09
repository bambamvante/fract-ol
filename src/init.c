/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:41:36 by arphueng          #+#    #+#             */
/*   Updated: 2025/05/09 20:28:33 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_set(t_fractol *f, char *av)
{
	int	len;
	int	i;

	len = ft_strlen(av);
	i = 0;
	while (av[i])
	{
		av[i] = ft_tolower(av[i]);
		i++;
	}
	if (!ft_strncmp(av, "mandelbrot", 10) && len == 10)
		f->set = MANDELBROT;
	else if (!ft_strncmp(av, "julia", 5) && len == 5)
		f->set = JULIA;
	else
		ft_exit(ERROR_MSG, EXIT_FAILURE);
}

void	init_fractol(t_fractol *f)
{
	f->mlx = mlx_init(WIDTH, HEIGHT, NAME, false);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(f->mlx, f->img, 0, 0);
	mlx_key_hook(f->mlx, key_handler, f);
	mlx_scroll_hook(f->mlx, scroll_handler, f);
	mlx_close_hook(f->mlx, close_handler, f);
	f->x = 0;
	f->y = 0;
	f->max_iter = 50;
	f->need_to_draw = true;
	f->zoom = 1.0;
	f->scale = 200;
	f->xdelta = 0.0;
	f->ydelta = 0.0;
}

void	clear_fractol(void *param)
{
	t_fractol	*f;

	f = (t_fractol *)(param);
	if (f->img)
		mlx_delete_image(f->mlx, f->img);
	if (f->mlx)
		mlx_terminate(f->mlx);
	ft_exit(NULL, EXIT_SUCCESS);
}
