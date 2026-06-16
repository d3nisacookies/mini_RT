/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaung <akaung@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:57:38 by akaung            #+#    #+#             */
/*   Updated: 2026/06/16 15:06:34 by akaung           ###   ########.fr       */
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

double	intersect_sphere(t_ray ray, t_sphere sphere)
{
	t_vec3	oc;
	t_vec3	v;
	double	discriminant;
	double	t;

	oc = vec_sub(ray.origin, sphere.center);
	v.x = vec_dot(ray.direction, ray.direction);
	v.y = 2 * (vec_dot(ray.direction, oc));
	v.z = (vec_dot(oc, oc) - (sphere.radius * sphere.radius));
	discriminant = (v.y * v.y) - (4 * v.x * v.z);
	if (discriminant < 0)
		return (-1);
	t = (-v.y - sqrt(discriminant)) / (2 * v.x);
	if (t < 0)
	{
		t = (-v.y + sqrt(discriminant)) / (2 * v.x);
		if (t < 0)
			return (-1);
	}
	return (t);
}
