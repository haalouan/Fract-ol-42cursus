/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:10:00 by haalouan          #+#    #+#             */
/*   Updated: 2024/03/06 19:48:11 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

double	map(double x, double min, double max)
{
	double	i;
	double	k;

	i = (max - min) * x;
	k = i / 800;
	return (k + min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

int	color_generator(int i)
{
	t_color	color;

	color.red = (i * 17) % 256;
	color.green = (i * 23) % 256;
	color.blue = (i * 31) % 256;
	return (color.red << 16 | color.green << 8 | color.blue);
}

int	destroy(t_fractal *fractal)
{
	ft_putstr_fd("window closed", 1);
	mlx_destroy_window(fractal->mlx_conx, fractal->mlx_wind);
	exit (0);
}
