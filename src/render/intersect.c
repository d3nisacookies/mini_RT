/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tswe-zin <tswe-zin@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 19:41:58 by tswe-zin          #+#    #+#             */
/*   Updated: 2026/07/18 21:58:59 by tswe-zin         ###   ########.fr       */
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
	double		t;
	t_cyl_hit	h;

	h.top = vec_add(cyl.center,
			vec_scale(cyl.axis, cyl.height / 2.0));
	h.bottom = vec_sub(cyl.center,
			vec_scale(cyl.axis, cyl.height / 2.0));
	h.body = intersect_cylinder_body(ray, cyl);
	h.cap1 = intersect_disk(ray,
			h.top,
			cyl.axis,
			cyl.radius);
	h.cap2 = intersect_disk(ray,
			h.bottom,
			cyl.axis,
			cyl.radius);
	t = min_positive(h.body, h.cap1);
	t = min_positive(t, h.cap2);
	return (t);
}
