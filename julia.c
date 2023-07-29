/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 08:34:03 by nsion             #+#    #+#             */
/*   Updated: 2023/07/27 13:24:15 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	int	i;

	i = 0;
	while (((char *)s1)[i] && ((char *)s1)[i] == ((char *)s2)[i] && n--)
		i++;
	if (!n)
		return (0);
	return (((char *)s1)[i] - ((char *)s2)[i]);
}

void	julia_pixel(t_data *img, int x, int y)
{
	int		iter;
	double	tmp;
	double	zx;
	double	zy;

	zx = (-2.0 + (double)x / 1000 * (2.0 - -2.0)) / img->zoom + img->offset_x;
	zy = (-2.0 + (double)y / 1000 * (2.0 - -2.0)) / img->zoom + img->offset_y;
	iter = 0;
	while (zx * zx + zy * zy <= 4.0 && iter < 128)
	{
		tmp = zx * zx - zy * zy + img->av_x;
		zy = 2.0 * zx * zy + img->av_y;
		zx = tmp;
		iter++;
	}
	my_mlx_pixel_put(img, x, y, img->color * iter);
}

void	julia(t_data *img)
{
	int		y;
	int		x;

	y = 0;
	while (y < 1000)
	{
		x = 0;
		while (x < 1000)
		{
			julia_pixel(img, x, y);
			x++;
		}
		y++;
	}
}
