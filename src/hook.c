/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:43:39 by arphueng          #+#    #+#             */
/*   Updated: 2025/05/09 13:02:06 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>

void	key_handler(mlx_key_data_t key_type, void *param)
{
	if (key_type.key == MLX_KEY_ESCAPE)
		clear_fractol(param);
}

void	scroll_handler(double xdelta, double ydelta, void *param)
{
	t_fractol	*f;
	t_complex	before;
	t_complex	after;
	int			mouse_x;
	int			mouse_y;

	f = (t_fractol *)param;
	(void)xdelta;
	mlx_get_mouse_pos(f->mlx, &mouse_x, &mouse_y);
	before = cartesian_to_complex(*f, mouse_x, mouse_y);
	if (ydelta > 0 && f->zoom < ZOOM_MAX)
		f->zoom *= ZOOM_FACTOR;
	else if (ydelta < 0 && f->zoom > ZOOM_MIN)
		f->zoom /= ZOOM_FACTOR;
	after = cartesian_to_complex(*f, mouse_x, mouse_y);
	f->xdelta += before.re - after.re;
	f->ydelta += before.im - after.im;
	f->need_to_draw = true;
}

void	close_handler(void *param)
{
	clear_fractol(param);
}

void	redraw(void *param)
{
	t_fractol	*f;

	f = (t_fractol *)param;
	if (f->need_to_draw)
	{
		draw(f);
		mlx_image_to_window(f->mlx, f->img, 0, 0);
		f->need_to_draw = false;
	}
}
