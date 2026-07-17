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

double	min_positive(double a, double b)
{
	if (a < 0)
		return (b);
	if (b < 0)
		return (a);
	if (a < b)
		return (a);
	return (b);
}

double	intersect_cylinder_body(t_ray ray, t_cylinder cyl)
{
	t_vec3	oc;
	t_vec3	dp;
	t_vec3	ocp;
	double	a;
	double	b;
	double	c;
	double	d;
	double	t1;
	double	t2;
	double	m;

	oc = vec_sub(ray.origin, cyl.center);
	dp = vec_sub(ray.direction,
			vec_scale(cyl.axis,
			vec_dot(ray.direction, cyl.axis)));
	ocp = vec_sub(oc,
			vec_scale(cyl.axis,
			vec_dot(oc, cyl.axis)));
	a = vec_dot(dp, dp);
	b = 2.0 * vec_dot(dp, ocp);
	c = vec_dot(ocp, ocp) - cyl.radius * cyl.radius;
	d = b * b - 4 * a * c;
	if (d < 0)
		return (-1);
	t1 = (-b - sqrt(d)) / (2 * a);
	t2 = (-b + sqrt(d)) / (2 * a);
	if (t1 > 1e-6)
	{
		m = vec_dot(
			vec_add(oc, vec_scale(ray.direction, t1)),
			cyl.axis);
		if (fabs(m) <= cyl.height / 2.0)
			return (t1);
	}
	if (t2 > 1e-6)
	{
		m = vec_dot(
			vec_add(oc, vec_scale(ray.direction, t2)),
			cyl.axis);
		if (fabs(m) <= cyl.height / 2.0)
			return (t2);
	}
	return (-1);
}

double	intersect_disk(t_ray ray, t_vec3 center,
		t_vec3 normal, double radius)
{
	double	t;
	double	denom;
	t_vec3	hit;
	t_vec3	diff;

	denom = vec_dot(ray.direction, normal);
	if (fabs(denom) < 1e-6)
		return (-1);
	t = vec_dot(vec_sub(center, ray.origin), normal) / denom;
	if (t <= 1e-6)
		return (-1);
	hit = vec_add(ray.origin, vec_scale(ray.direction, t));
	diff = vec_sub(hit, center);
	if (vec_dot(diff, diff) > radius * radius)
		return (-1);
	return (t);
}
