/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tswe-zin <tswe-zin@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 19:41:58 by tswe-zin          #+#    #+#             */
/*   Updated: 2026/07/18 22:00:10 by tswe-zin         ###   ########.fr       */
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

double	check_cylinder_hit(t_ray ray, t_cylinder cyl,
			t_vec3 oc, double t)
{
	double	m;

	if (t <= 1e-6)
		return (-1);
	m = vec_dot(vec_add(oc, vec_scale(ray.direction, t)),
			cyl.axis);
	if (fabs(m) <= cyl.height / 2.0)
		return (t);
	return (-1);
}

void	init_cylinder_quad(t_ray ray, t_cylinder cyl,
			t_cyl_quad *q)
{
	q->oc = vec_sub(ray.origin, cyl.center);
	q->dp = vec_sub(ray.direction,
			vec_scale(cyl.axis,
				vec_dot(ray.direction, cyl.axis)));
	q->ocp = vec_sub(q->oc,
			vec_scale(cyl.axis,
				vec_dot(q->oc, cyl.axis)));
	q->a = vec_dot(q->dp, q->dp);
	q->b = 2.0 * vec_dot(q->dp, q->ocp);
	q->c = vec_dot(q->ocp, q->ocp)
		- cyl.radius * cyl.radius;
	q->d = q->b * q->b - 4 * q->a * q->c;
}

double	intersect_cylinder_body(t_ray ray, t_cylinder cyl)
{
	t_cyl_quad	q;
	double		t;

	init_cylinder_quad(ray, cyl, &q);
	if (fabs(q.a) < 1e-6 || q.d < 0)
		return (-1);
	t = check_cylinder_hit(ray, cyl, q.oc,
			(-q.b - sqrt(q.d)) / (2 * q.a));
	if (t > 0)
		return (t);
	return (check_cylinder_hit(ray, cyl, q.oc,
			(-q.b + sqrt(q.d)) / (2 * q.a)));
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
