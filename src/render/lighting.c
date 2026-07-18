/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tswe-zin <tswe-zin@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:22:24 by akaung            #+#    #+#             */
/*   Updated: 2026/07/18 21:52:05 by tswe-zin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_RT.h"

t_vec3	cylinder_normal(t_vec3 hit, t_cylinder cyl)
{
	t_vec3	top;
	t_vec3	bottom;
	t_vec3	v;
	double	proj;

	top = vec_add(cyl.center,
			vec_scale(cyl.axis, cyl.height / 2.0));
	bottom = vec_sub(cyl.center,
			vec_scale(cyl.axis, cyl.height / 2.0));
	if (fabs(vec_dot(vec_sub(hit, top), cyl.axis)) < 1e-4)
		return (cyl.axis);
	if (fabs(vec_dot(vec_sub(hit, bottom), cyl.axis)) < 1e-4)
		return (vec_scale(cyl.axis, -1));
	v = vec_sub(hit, cyl.center);
	proj = vec_dot(v, cyl.axis);
	return (vec_normalize(
			vec_sub(v, vec_scale(cyl.axis, proj))));
}

t_hit	compute_hit(t_ray ray, t_object *obj, t_light light, double t)
{
	t_hit	hit;

	hit.p = vec_add(ray.origin, vec_scale(ray.direction, t));
	if (obj->type == SPHERE)
	{
		hit.normal = vec_normalize(
				vec_sub(hit.p, obj->sphere.center));
		hit.color = obj->sphere.color;
	}
	else if (obj->type == PLANE)
	{
		hit.normal = obj->plane.normal;
		hit.color = obj->plane.color;
	}
	else if (obj->type == CYLINDER)
	{
		hit.normal = cylinder_normal(hit.p, obj->cylinder);
		hit.color = obj->cylinder.color;
	}
	hit.light_dir = vec_normalize(
			vec_sub(light.position, hit.p));
	hit.light_distance = vec_length(vec_sub(light.position, hit.p));
	return (hit);
}

static t_vec3	apply_color(t_vec3 obj_color, t_vec3 ambient_term)
{
	t_vec3	color;

	color.x = clamp(((obj_color.x * ambient_term.x) / 255), 0, 255);
	color.y = clamp(((obj_color.y * ambient_term.y) / 255), 0, 255);
	color.z = clamp(((obj_color.z * ambient_term.z) / 255), 0, 255);
	return (color);
}

static t_vec3	compute_light_term(t_hit hit, t_scene *scene)
{
	t_vec3	ambient_term;
	t_vec3	light_term;
	double	diffuse;

	ambient_term = vec_scale(scene->ambient.color,
			scene->ambient.ratio);
	if (is_in_shadow(
			vec_add(hit.p, vec_scale(hit.normal, 1e-4)),
			hit.light_dir,
			hit.light_distance,
			scene))
		return (ambient_term);
	diffuse = vec_dot(hit.normal, hit.light_dir);
	if (diffuse < 0)
		diffuse = 0;
	light_term = vec_add(
			ambient_term,
			vec_scale(scene->light.colour,
				scene->light.brightness * diffuse));
	return (light_term);
}

t_vec3	compute_lighting(t_ray ray, t_object *obj, double t, t_scene *scene)
{
	t_hit	hit;
	t_vec3	color;
	t_vec3	light_term;

	hit = compute_hit(ray, obj, scene->light, t);
	if (obj->type == SPHERE)
		color = obj->sphere.color;
	else if (obj->type == PLANE)
		color = obj->plane.color;
	else
		color = obj->cylinder.color;
	light_term = compute_light_term(hit, scene);
	return (apply_color(color, light_term));
}
