/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:36:27 by nsion             #+#    #+#             */
/*   Updated: 2023/07/27 13:32:48 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <string.h>
# include "ft_printf/libftprintf.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define ESC 65307
# define W 119
# define E 101
# define R 114

typedef struct s_data{
	void	*mlx;
	void	*wi;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	double	zoom;
	double	offset_x;
	double	offset_y;
	int		choise;
	double	av_x;
	double	av_y;
	int		color;
}				t_data;

typedef struct s_xy{
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	new_zx;
	double	new_zy;
}			t_xy;
//fractol.c
double	powering(double f_, double s_);

int		ft_atoi(char *str);

void	init_img(t_data *img, double av_x, double av_y);

void	fractal_choise(int choise, double av_x, double av_y);

//macro.c
int		handle_close(t_data *data);

int		handle_events(int keycode, t_data *data);

int		mouse_scroll(int button, int x, int y, t_data *img);

void	redraw_fractal(t_data *img);

int		choise_color(int keycode, t_data *img);

//julia.c
int		ft_strncmp(char *s1, char *s2, size_t n);

void	julia(t_data *img);

void	julia_pixel(t_data *img, int x, int y);

//mandelbrot.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	mandelbrot_pixel(t_data *img, int x, int y);

void	mandelbrot(t_data *img);

//burning_ship.c
void	burningship_pixel(t_data *img, int x, int y, t_xy xy);

void	burningship(t_data *img);

#endif
