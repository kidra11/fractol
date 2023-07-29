/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:02:22 by nsion             #+#    #+#             */
/*   Updated: 2023/07/27 13:25:01 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_events(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->wi);
		mlx_loop_end(data->mlx);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(EXIT_SUCCESS);
	}
	else
		choise_color(keycode, data);
	return (0);
}

int	handle_close(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->wi);
	mlx_loop_end(data->mlx);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

int	mouse_scroll(int button, int x, int y, t_data *img)
{
	double	zoom_factor;

	zoom_factor = 1.1;
	if (button == 4)
	{
		img->zoom *= zoom_factor;
		img->offset_x += (x - img->width / 2) / (img->width / 2) / img->zoom;
		img->offset_y += (y - img->height / 2) / (img->height / 2) / img->zoom;
	}
	if (button == 5)
	{
		img->zoom /= zoom_factor;
		img->offset_x -= (x - img->width / 2) / (img->width / 2) / img->zoom;
		img->offset_y -= (y - img->height / 2) / (img->height / 2) / img->zoom;
	}
	redraw_fractal(img);
	return (0);
}

void	redraw_fractal(t_data *img)
{
	mlx_clear_window(img->mlx, img->wi);
	if (img->choise == 1)
		julia(img);
	if (img->choise == 2)
		mandelbrot(img);
	if (img->choise == 3)
		burningship(img);
	mlx_put_image_to_window(img->mlx, img->wi, img->img, 0, 0);
}

int	choise_color(int keycode, t_data *img)
{
	if (keycode == W)
		img->color = 0x003400;
	else if (keycode == E)
		img->color = 0x000011;
	else if (keycode == R)
		img->color = 0x240000;
	else
		img->color = 0xFF00CE;
	redraw_fractal(img);
	return (0);
}
