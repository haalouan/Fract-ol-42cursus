/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:17:57 by haalouan          #+#    #+#             */
/*   Updated: 2024/02/26 22:22:23 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	check_s2(char *s2)
{
	int	point2;

	point2 = 0;
	while (*s2 != '\0')
	{
		if ((*s2 > '9' || *s2 < '0') && *s2 != '.')
			return (1);
		if (*s2 == '.')
			point2++;
		s2++;
	}
	if (point2 > 1)
		return (1);
	return (0);
}

int	check_s1(char *s1)
{
	int	point1;

	point1 = 0;
	while (*s1 != '\0')
	{
		if (!((*s1 <= '9' && *s1 >= '0') || *s1 == '.'))
			return (1);
		if (*s1 == '.')
			point1++;
		s1++;
	}
	if (point1 > 1)
		return (1);
	return (0);
}

int	check_errors(char *s1, char *s2)
{
	int	ret1;
	int	ret2;

	ret1 = 0;
	ret2 = 0;
	while (*s1 == ' ')
		s1++;
	while (*s2 == ' ')
		s2++;
	if (!s1 || !s2)
		return (1);
	if (*s1 == '.' || *s2 == '.')
	{
		return (1);
	}
	if (*s1 == '+' || *s1 == '-')
		s1++;
	if (*s2 == '+' || *s2 == '-')
		s2++;
	ret1 = check_s1(s1);
	ret2 = check_s2(s2);
	if (ret1 == 1 || ret2 == 1)
		return (1);
	return (0);
}

void	error_send_and_free(t_fractal *fractal)
{
	free(fractal);
	ft_putstr_fd("ERROR please enter valid ARGS\n", 2);
	exit(1);
}
