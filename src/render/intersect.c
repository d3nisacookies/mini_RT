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

double	intersect_plane(t_ray ray, t_plane plane)
{
	double	t;
	t_vec3	diff;
	double	numerator;
	double	denominator;

	diff = vec_sub(plane.point, ray.origin);
	numerator = vec_dot(diff, plane.normal);
	denominator = vec_dot(ray.direction, plane.normal);
	if (fabs(denominator) < 1e-6)
		return (-1);
	t = numerator / denominator;
	if (t <= 1e-6)
		return (-1);
	return (t);
}

double	intersect_cylinder(t_ray ray, t_cylinder cyl)
{
	t_vec3	top;
	t_vec3	bottom;
	double	body;
	double	cap1;
	double	cap2;
	double	t;

	top = vec_add(cyl.center,
			vec_scale(cyl.axis, cyl.height / 2.0));
	bottom = vec_sub(cyl.center,
			vec_scale(cyl.axis, cyl.height / 2.0));
	body = intersect_cylinder_body(ray, cyl);
	cap1 = intersect_disk(ray,
			top,
			cyl.axis,
			cyl.radius);
	cap2 = intersect_disk(ray,
			bottom,
			cyl.axis,
			cyl.radius);
	t = min_positive(body, cap1);
	t = min_positive(t, cap2);
	return (t);
}
