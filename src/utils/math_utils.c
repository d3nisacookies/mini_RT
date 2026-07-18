/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tswe-zin <tswe-zin@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:57:38 by akaung            #+#    #+#             */
/*   Updated: 2026/07/18 21:51:02 by tswe-zin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_RT.h"

t_vec3	vec_sub(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	return (result);
}

double	vec_dot(t_vec3 a, t_vec3 b)
{
	double	result;

	result = a.x * b.x + a.y * b.y + a.z * b.z;
	return (result);
}

t_vec3	vec_scale(t_vec3 v, double t)
{
	t_vec3	result;

	result.x = v.x * t;
	result.y = v.y * t;
	result.z = v.z * t;
	return (result);
}

t_vec3	vec_add(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	return (result);
}

int	color_to_int(t_vec3 color)
{
	int	r;
	int	g;
	int	b;

	r = (int)color.x;
	g = (int)color.y;
	b = (int)color.z;
	return ((r << 16) | (g << 8) | b);
}
