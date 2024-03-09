/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_helpers1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:14:10 by haalouan          #+#    #+#             */
/*   Updated: 2024/02/26 22:25:26 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s != '\0')
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
	}
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
	{
		write(fd, &c, 1);
	}
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	while (n > 0)
	{
		if (*str1 == '\0' || *str2 == '\0' || *str1 != *str2)
			return ((unsigned char)(*str1) - (unsigned char)(*str2));
		str1++;
		str2++;
		n--;
	}
	return (0);
}

double	ft_atoi_double(const char *str)
{
	double	result_int;
	double	result_frac;
	int		signe;
	double	pow;

	result_int = 0;
	result_frac = 0;
	signe = 1;
	pow = 1;
	while (*str == 32 || (*str <= 13 && *str >= 9))
		++str;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			signe = -1;
	while (*str != '.' && *str <= '9' && *str >= '0')
		result_int = (result_int * 10) + (*str++ - 48);
	if (*str == '.')
		++str;
	while (*str <= '9' && *str >= '0')
	{
		pow /= 10;
		result_frac = result_frac + (*str++ - 48) * pow;
	}
	return ((result_int + result_frac) * signe);
}
