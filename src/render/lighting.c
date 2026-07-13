/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaung <akaung@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:22:24 by akaung            #+#    #+#             */
/*   Updated: 2026/06/16 14:54:08 by akaung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_RT.h"

static t_hit	compute_hit(t_ray ray, t_sphere sphere, t_light light, double t)
{
	t_hit	hit;

	hit.p = vec_add(ray.origin, vec_scale(ray.direction, t));
	hit.normal = vec_normalize(vec_sub(hit.p, sphere.center));
	hit.light_dir = vec_normalize(vec_sub(light.position, hit.p));
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

t_vec3	compute_lighting(t_ray ray, t_object *obj, double t, t_scene *scene)
{
	t_hit	hit;
	t_vec3	ambient_term;
	double	diffuse;

	hit = compute_hit(ray, obj->sphere, scene->light, t);
	ambient_term = vec_scale(scene->ambient.color, scene->ambient.ratio);
	if (is_in_shadow(vec_add(hit.p, vec_scale(hit.normal, 1e-4)),
			hit.light_dir, hit.light_distance, scene))
		return (apply_color(obj->sphere.color, ambient_term));
	diffuse = vec_dot(hit.normal, hit.light_dir);
	if (diffuse < 0)
		diffuse = 0;
	return (apply_color(obj->sphere.color,
			vec_add(ambient_term, vec_scale(scene->light.colour,
					scene->light.brightness * diffuse))));
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
