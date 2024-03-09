/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:02:30 by haalouan          #+#    #+#             */
/*   Updated: 2024/03/06 22:52:56 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}				t_color;

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct s_fractal
{
	void		*mlx_conx;
	void		*mlx_wind;
	t_img		img;
	int			color;
	char		*name;
	int			nbr_iterations;
	double		shift;
	double		zoom;
	int			k;
	double		x_julia;
	double		y_julia;
	t_complex	mouse;
	double		max_x;
	double		min_x;
	double		max_y;
	double		min_y;
	double		shift_x;
	double		shift_y;
}				t_fractal;

void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
double		ft_atoi_double(const char *str);
double		map(double x, double new_min, double new_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
int			color_generator(int i);
void		free_img(t_fractal *fractal);
void		free_window(t_fractal *fractal);
void		free_fractal(t_fractal *fractal);
int			key_handle(int keycode, t_fractal *fractal);
void		fractal_moves(t_fractal *fractal);
void		fractal_init(t_fractal *fractal);
void		fractal_init_bonus(t_fractal *fractal);
void		fractal_moves_bonus(t_fractal *fractal);
int			key_handle_bonus(int keycode, t_fractal *fractal);
int			mouse_handle_bonus(int keycode, int x, int y, t_fractal *fractal);
void		error_send_and_free(t_fractal *fractal);
int			check_errors(char *s1, char *s2);
int			check_s1(char *s1);
int			check_s2(char *s2);
void		fractal_burning_ship_moves(t_fractal *fractal);
int			mouse_handle_burning_ship(int keycode, int mx, int my,
				t_fractal *fractal);
int			key_handle_burning_ship(int keycode, t_fractal *fractal);
int			destroy(t_fractal *fractal);
int			mouse_handel(int keycode, int mx, int my, t_fractal*fractal);
#endif
