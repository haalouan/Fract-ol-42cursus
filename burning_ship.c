/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:30:21 by haalouan          #+#    #+#             */
/*   Updated: 2024/02/26 22:22:17 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void	my_mlx_pixel_put_burning_ship(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static t_complex	burning_ship(t_complex c, t_complex z)
{
	double	temp;

	temp = (z.x * z.x) - (z.y * z.y) + c.x;
	z.y = fabs(2 * z.x * z.y) + c.y;
	z.x = temp;
	return (z);
}

static void	handle_pixels_burning_ship(int x, int y, t_fractal *fractal)
{
	int			i;
	int			j;
	t_complex	c;
	t_complex	z;

	c.x = map(x, fractal->min_x, fractal->max_x);
	c.y = map(y, fractal->min_y, fractal->max_y);
	z.x = 0;
	z.y = 0;
	i = 0;
	j = 0;
	if (fractal->k != 0)
		j = fractal->k;
	while (i++ < fractal->nbr_iterations)
	{
		z = burning_ship(c, z);
		if (((z.x * z.x) + (z.y * z.y)) > 4)
		{
			fractal->color = color_generator(j);
			my_mlx_pixel_put_burning_ship(&fractal->img, x, y, fractal->color);
			return ;
		}
		my_mlx_pixel_put_burning_ship(&fractal->img, x, y, 0x000000);
		j++;
	}
}

void	fractal_burning_ship_moves(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < 800)
	{
		x = -1;
		while (++x < 800)
			handle_pixels_burning_ship(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx_conx, fractal->mlx_wind,
		fractal->img.img_ptr, 0, 0);
}
