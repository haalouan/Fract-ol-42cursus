/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 00:53:26 by haalouan          #+#    #+#             */
/*   Updated: 2024/03/09 17:12:44 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static t_complex	mandel_or_julia(t_complex *z, int x, int y,
	t_fractal *fractal)
{
	t_complex	c;

	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c.x = fractal->x_julia;
		c.y = fractal->y_julia;
		z->x = (map(x, fractal->min_x, fractal->max_x)
				* fractal->zoom) + fractal->shift_x;
		z->y = (map(y, fractal->min_y, fractal->max_y)
				* fractal->zoom) + fractal->shift_y;
	}
	else
	{
		c.x = (map(x, fractal->min_x, fractal->max_x)
				* fractal->zoom) + fractal->shift_x;
		c.y = (map(y, fractal->min_y, fractal->max_y)
				* fractal->zoom) + fractal->shift_y;
		z->x = 0;
		z->y = 0;
	}
	return (c);
}

static void	handle_pixels(int x, int y, t_fractal *fractal)
{
	int			i;
	t_complex	z;
	t_complex	c;

	c = mandel_or_julia(&z, x, y, fractal);
	i = 0;
	while (i++ < fractal->nbr_iterations)
	{
		z = sum_complex(square_complex(z), c);
		if (((z.x * z.x) + (z.y * z.y)) > 4)
		{
			fractal->color = color_generator(i);
			my_mlx_pixel_put(&fractal->img, x, y, fractal->color);
			return ;
		}
		my_mlx_pixel_put(&fractal->img, x, y, 0x000000);
	}
}

void	fractal_moves(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < 800)
	{
		x = -1;
		while (++x < 800)
			handle_pixels(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx_conx, fractal->mlx_wind,
		fractal->img.img_ptr, 0, 0);
}
