/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_shadow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tswe-zin <tswe-zin@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:22:33 by akaung            #+#    #+#             */
/*   Updated: 2026/07/18 21:41:49 by tswe-zin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_RT.h"

int	is_in_shadow(t_vec3 p, t_vec3 light_direction,
				double light_distance, t_scene *scene)
{
	t_ray		shadow_ray;
	double		t;
	t_object	*obj;

	shadow_ray.origin = vec_add(p, vec_scale(light_direction, 1e-4));
	shadow_ray.direction = light_direction;
	obj = scene->objects;
	while (obj)
	{
		t = -1;
		if (obj->type == SPHERE)
			t = intersect_sphere(shadow_ray, obj->sphere);
		else if (obj->type == PLANE)
			t = intersect_plane(shadow_ray, obj->plane);
		else if (obj->type == CYLINDER)
			t = intersect_cylinder(shadow_ray, obj->cylinder);
		if (t > 0 && t < light_distance)
			return (1);
		obj = obj->next;
	}
	return (0);
}
