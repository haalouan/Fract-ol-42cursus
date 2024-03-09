/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:11:45 by haalouan          #+#    #+#             */
/*   Updated: 2024/03/09 17:09:58 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void	julia_bonus(t_fractal *fractal, char *s1, char *s2)
{
	if (check_errors(s1, s2) == 1)
		error_send_and_free(fractal);
	fractal_init_bonus(fractal);
	fractal->x_julia = ft_atoi_double(s1);
	fractal->y_julia = ft_atoi_double(s2);
	fractal_moves_bonus(fractal);
	mlx_hook(fractal->mlx_wind, 2, 0, key_handle_bonus, fractal);
	mlx_hook(fractal->mlx_wind, 4, 0, mouse_handle_bonus, fractal);
	mlx_hook(fractal->mlx_wind, 17, 0, destroy, fractal);
	mlx_loop(fractal->mlx_conx);
	exit(0);
}

static void	burning_ship(t_fractal *fractal)
{
	fractal_init_bonus(fractal);
	fractal_burning_ship_moves(fractal);
	mlx_hook(fractal->mlx_wind, 2, 0, key_handle_burning_ship, fractal);
	mlx_hook(fractal->mlx_wind, 4, 0, mouse_handle_burning_ship, fractal);
	mlx_hook(fractal->mlx_wind, 17, 0, destroy, fractal);
	mlx_loop(fractal->mlx_conx);
	exit(0);
}

int	main(int arc, char **arv)
{
	t_fractal	*fractal;

	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
		exit(1);
	fractal->name = arv[1];
	if (arc == 2 && !ft_strncmp(arv[1], "mandelbrot", 10))
	{
		fractal_init_bonus(fractal);
		fractal_moves_bonus(fractal);
		mlx_hook(fractal->mlx_wind, 2, 0, key_handle_bonus, fractal);
		mlx_hook(fractal->mlx_wind, 4, 0, mouse_handle_bonus, fractal);
		mlx_hook(fractal->mlx_wind, 17, 0, destroy, fractal);
		mlx_loop(fractal->mlx_conx);
	}
	else if (arc == 4 && !ft_strncmp(arv[1], "julia", 5))
		julia_bonus(fractal, arv[2], arv[3]);
	else if (arc == 2 && !ft_strncmp(arv[1], "burning_ship", 12))
		burning_ship(fractal);
	else
		error_send_and_free(fractal);
}
