/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:23:10 by nsion             #+#    #+#             */
/*   Updated: 2023/07/29 12:26:18 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

void	burningship_pixel(t_data *img, int x, int y, t_xy xy)
{
	int		iter;
	double	tmp;

	iter = 0;
	xy.zx = 0;
	xy.zy = 0;
	xy.cx = (x - img->width / 2) / img->zoom + img->offset_x;
	xy.cy = (y - img->height / 2) / img->zoom + img->offset_y;
	while (xy.zx * xy.zx + xy.zy * xy.zy <= 4.0 && iter < 128)
	{
		tmp = xy.zx * xy.zx - xy.zy * xy.zy + xy.cx;
		xy.zy = fabs(2.0 * xy.zx * xy.zy) + xy.cy;
		xy.zx = fabs(tmp);
		iter++;
	}
	my_mlx_pixel_put(img, x, y, img->color * iter);
}

void	burningship(t_data *img)
{
	int		y;
	int		x;
	t_xy	xy;

	y = 0;
	while (y < 1000)
	{
		x = 0;
		while (x < 1000)
		{
			burningship_pixel(img, x, y, xy);
			x++;
		}
		y++;
	}
}
