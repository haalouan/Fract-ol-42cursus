/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:08:35 by haalouan          #+#    #+#             */
/*   Updated: 2024/03/09 17:11:08 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void	moves(t_fractal *fractal, int keycode)
{
	if (keycode == 124)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keycode == 123)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keycode == 126)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keycode == 125)
		fractal->shift_y -= (0.5 * fractal->zoom);
}

int	key_handle(int keycode, t_fractal *fractal)
{
	if (keycode == 53)
	{
		ft_putstr_fd("window closed!\n", 1);
		mlx_destroy_window(fractal->mlx_conx, fractal->mlx_wind);
		exit (0);
	}
	moves(fractal, keycode);
	fractal_moves(fractal);
	return (0);
}

int	mouse_handel(int keycode, int mx, int my, t_fractal*fractal)
{
	if (keycode == 5)
	{
		fractal->nbr_iterations += 10;
		fractal->zoom *= 0.8;
	}
	else if (keycode == 4)
	{
		fractal->nbr_iterations -= 10;
		fractal->zoom *= 1.2;
	}
	(void)mx;
	(void)my;
	fractal_moves(fractal);
	return (0);
}
