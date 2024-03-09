/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:05:41 by haalouan          #+#    #+#             */
/*   Updated: 2024/03/09 21:17:31 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void	julia(t_fractal *fractal, char *s1, char *s2)
{
	if (check_errors(s1, s2) == 1)
		error_send_and_free(fractal);
	fractal_init(fractal);
	fractal->x_julia = ft_atoi_double(s1);
	fractal->y_julia = ft_atoi_double(s2);
	fractal_moves(fractal);
	mlx_hook(fractal->mlx_wind, 2, 0, key_handle, fractal);
	mlx_hook(fractal->mlx_wind, 4, 0, mouse_handel, fractal);
	mlx_hook(fractal->mlx_wind, 17, 0, destroy, fractal);
	mlx_loop(fractal->mlx_conx);
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
		fractal_init(fractal);
		fractal_moves(fractal);
		mlx_hook(fractal->mlx_wind, 2, 0, key_handle, fractal);
		mlx_hook(fractal->mlx_wind, 4, 0, mouse_handel, fractal);
		mlx_hook(fractal->mlx_wind, 17, 0, destroy, fractal);
		mlx_loop(fractal->mlx_conx);
	}
	else if (arc == 4 && !ft_strncmp(arv[1], "julia", 5))
		julia(fractal, arv[2], arv[3]);
	else
		error_send_and_free(fractal);
}
