/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:14:40 by haalouan          #+#    #+#             */
/*   Updated: 2024/03/06 19:48:02 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void	zoom_out(t_fractal *fractal, int keycode)
{
	if (keycode == 4)
	{
		fractal->min_x /= fractal->zoom;
		fractal->max_x /= fractal->zoom;
		fractal->max_y /= fractal->zoom;
		fractal->min_y /= fractal->zoom;
		fractal->min_x -= fractal->mouse.x;
		fractal->max_x -= fractal->mouse.x;
		fractal->min_y -= fractal->mouse.y;
		fractal->max_y -= fractal->mouse.y;
		fractal->nbr_iterations -= 20;
		fractal->shift *= 2;
	}
}

int	mouse_handle_bonus(int keycode, int mx, int my, t_fractal *fractal)
{
	fractal->mouse.x = map(mx, fractal->min_x, fractal->max_x);
	fractal->mouse.y = map(my, fractal->min_y, fractal->max_y);
	if (keycode == 5)
	{
		fractal->nbr_iterations += 20;
		fractal->min_x += fractal->mouse.x;
		fractal->max_x += fractal->mouse.x;
		fractal->min_y += fractal->mouse.y;
		fractal->max_y += fractal->mouse.y;
		fractal->min_x *= fractal->zoom;
		fractal->max_x *= fractal->zoom;
		fractal->max_y *= fractal->zoom;
		fractal->min_y *= fractal->zoom;
		fractal->shift /= 2;
	}
	zoom_out(fractal, keycode);
	fractal_moves_bonus(fractal);
	return (0);
}

static void	moves_bonus(t_fractal *fractal, int keycode)
{
	if (keycode == 126)
	{
		fractal->min_y += fractal->shift;
		fractal->max_y += fractal->shift;
	}
	else if (keycode == 125)
	{
		fractal->min_y -= fractal->shift;
		fractal->max_y -= fractal->shift;
	}
	else if (keycode == 49)
	{
		fractal->k += 1;
	}
	if (keycode == 82)
	{
		fractal->max_x = 2;
		fractal->max_y = -2;
		fractal->min_x = -2;
		fractal->min_y = 2;
		fractal->k = 0;
	}
}

int	key_handle_bonus(int keycode, t_fractal *fractal)
{
	if (keycode == 53)
	{
		ft_putstr_fd("window closed!\n", 1);
		mlx_destroy_window(fractal->mlx_conx, fractal->mlx_wind);
		exit (0);
	}
	else if (keycode == 124)
	{
		fractal->min_x += fractal->shift;
		fractal->max_x += fractal->shift;
	}
	else if (keycode == 123)
	{
		fractal->min_x -= fractal->shift;
		fractal->max_x -= fractal->shift;
	}
	moves_bonus(fractal, keycode);
	fractal_moves_bonus(fractal);
	return (0);
}
