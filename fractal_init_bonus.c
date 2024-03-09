/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:12:54 by haalouan          #+#    #+#             */
/*   Updated: 2024/03/05 15:23:57 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void	data_init(t_fractal *fractal)
{
	fractal->shift = 0.2;
	fractal->zoom = 0.5;
	fractal->k = 1;
	fractal->nbr_iterations = 70;
	fractal->max_y = -2;
	fractal->max_x = +2;
	fractal->min_y = +2;
	fractal->min_x = -2;
	if (!ft_strncmp(fractal->name, "burning_ship", 12))
	{
		fractal->min_y = -2;
		fractal->max_y = +2;
	}
}

void	fractal_init_bonus(t_fractal *fractal)
{
	fractal->mlx_conx = mlx_init();
	if (!fractal->mlx_conx)
	{
		free_fractal(fractal);
		exit(1);
	}
	fractal->mlx_wind = mlx_new_window(fractal->mlx_conx,
			800, 800, fractal->name);
	if (!fractal->mlx_wind)
	{
		free_window(fractal);
		exit(1);
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_conx, 800, 800);
	if (!fractal->img.img_ptr)
	{
		free_img(fractal);
		exit(1);
	}
	fractal->img.addr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bits_per_pixel, &fractal->img.line_length,
			&fractal->img.endian);
	data_init(fractal);
}
