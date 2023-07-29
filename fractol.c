/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:25:53 by nsion             #+#    #+#             */
/*   Updated: 2023/07/27 13:23:18 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	powering(double f_, double s_)
{
	return (pow(f_, -s_));
}

double	atod(char *s)
{
	double	g;
	int		i;
	double	n;
	double	c;

	g = 1;
	i = 0;
	n = 0;
	c = 1;
	if (s[i] == '-' || s[i] == '+')
		if (s[i++] == '-')
			g = -1;
	while (s[i] >= '0' && s[i] <= '9')
		n = n * 10 + s[i++] - 48;
	if (s[i] == '.' || s[i] == ',')
		while (s[++i] >= '0' && s[i] <= '9')
			n += (s[i] - 48) * powering(10, c++);
	if (s[i] != '\0')
		exit(ft_printf("ERROR : your argument must be a number\n"));
	return (n * g);
}

void	init_img(t_data *img, double av_x, double av_y)
{
	(void)img;
	img->width = 1000;
	img->height = 1000;
	img->zoom = 1;
	if (img->choise == 3)
		img->zoom = 100;
	img->offset_x = 0;
	img->offset_y = 0;
	img->av_x = av_x;
	img->av_y = av_y;
	img->color = 0xFF00CE;
}

void	fractal_choise(int choise, double av_x, double av_y)
{
	t_data	img;

	img.mlx = mlx_init();
	img.wi = mlx_new_window(img.mlx, 1000, 1000, "nom_window");
	img.img = mlx_new_image(img.mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	img.choise = choise;
	init_img(&img, av_x, av_y);
	if (choise == 1)
		julia(&img);
	if (choise == 2)
		mandelbrot(&img);
	if (choise == 3)
		burningship(&img);
	mlx_put_image_to_window(img.mlx, img.wi, img.img, 0, 0);
	mlx_mouse_hook(img.wi, mouse_scroll, &img);
	mlx_key_hook(img.wi, handle_events, &img);
	mlx_hook(img.wi, 17, 0, handle_close, &img);
	mlx_loop(img.mlx);
}

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		if (ft_strncmp(av[1], "julia", 6) == 0 && ac == 4)
		{
			if (atod(av[2]) <= 2 && atod(av[3]) <= 2)
				fractal_choise(1, atod(av[2]), atod(av[3]));
			else
				exit(ft_printf("ERROR : ./fractol julia x y\
					(-2 > x & y > 2)"));
		}
		if (ft_strncmp(av[1], "mandelbrot", 11) == 0)
			fractal_choise(2, 0, 0);
		if (ft_strncmp(av[1], "burningship", 13) == 0)
			fractal_choise(3, 0, 0);
		else if (ft_strncmp(av[1], "julia", 6) == 0 && ac != 4)
			exit(ft_printf("ERROR : you must have 2 \
				more argument smaller than 2"));
		else
			exit(ft_printf("ERROR : not a fractal_name\n"));
	}
	else
		exit(ft_printf("ERROR : Usage: ./fractol fractal_name\n"));
	return (0);
}
