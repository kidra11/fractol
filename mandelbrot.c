/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:58:53 by nsion             #+#    #+#             */
/*   Updated: 2023/07/27 13:25:40 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	mandelbrot_pixel(t_data *img, int x, int y)
{
	int		iter;
	double	pr;
	double	pi;
	t_xy	xy;

	pr = 1.5 * (x - img->width / 2) / (0.5 * img->zoom * img->width)
		+ img->offset_x;
	pi = (y - img->height / 2) / (0.5 * img->zoom * img->height)
		+ img->offset_y;
	xy.new_zx = 0;
	xy.new_zy = 0;
	iter = 0;
	while (xy.new_zx * xy.new_zx + xy.new_zy * xy.new_zy <= 4
		&& iter < 128)
	{
		xy.cx = xy.new_zx;
		xy.cy = xy.new_zy;
		xy.new_zx = xy.cx * xy.cx - xy.cy * xy.cy + pr;
		xy.new_zy = 2 * xy.cx * xy.cy + pi;
		iter++;
	}
	my_mlx_pixel_put(img, x, y, img->color * iter);
}

void	mandelbrot(t_data *img)
{
	int		y;
	int		x;

	y = 0;
	while (y < 1000)
	{
		x = 0;
		while (x < 1000)
		{
			mandelbrot_pixel(img, x, y);
			x++;
		}
		y++;
	}
}
