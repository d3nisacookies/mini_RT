/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tswe-zin <tswe-zin@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 19:41:58 by tswe-zin          #+#    #+#             */
/*   Updated: 2026/07/16 22:45:13 by tswe-zin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_RT.h"

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

double	intersect_sphere(t_ray ray, t_sphere sphere)
{
}

double	intersect_sphere(t_ray ray, t_sphere sphere)
{
}
