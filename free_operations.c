/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 00:53:11 by haalouan          #+#    #+#             */
/*   Updated: 2024/02/19 14:34:10 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	free_fractal(t_fractal *fractal)
{
	free(fractal->mlx_conx);
	free(fractal);
	ft_putstr_fd("Error initialising mlx conx", 2);
	exit(1);
}

void	free_window(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx_conx, fractal->mlx_wind);
	free(fractal->mlx_wind);
	free(fractal->mlx_conx);
	free(fractal);
	ft_putstr_fd("Error creating new window", 2);
	exit(1);
}

void	free_img(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_conx, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_conx, fractal->mlx_wind);
	free(fractal->mlx_wind);
	free(fractal->img.img_ptr);
	free(fractal->mlx_conx);
	free(fractal);
	ft_putstr_fd("Error creating new image", 2);
	exit(1);
}
