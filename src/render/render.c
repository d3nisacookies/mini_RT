/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tswe-zin <tswe-zin@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 12:39:45 by akaung            #+#    #+#             */
/*   Updated: 2026/07/16 22:46:43 by tswe-zin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_RT.h"

void	render(void *mlx, void *win, t_scene *scene)
{
	int		x;
	int		y;
	t_ray	ray;
	t_vec3	color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ray = get_camera_ray(&scene->camera, x, y);
			color = trace_ray(ray, scene);
			mlx_pixel_put(mlx, win, x, y, color_to_int(color));
			x++;
		}
		y++;
	}
}

static t_vec3	shade_closest(t_ray ray, t_object *obj
	, double t, t_scene *scene)
{
	return (compute_lighting(ray, obj, t, scene));
}

t_vec3	trace_ray(t_ray ray, t_scene *scene)
{
	t_object	*closest_obj;
	double		closest_t;

	closest_obj = find_closest_object(ray, scene, &closest_t);
	if (closest_obj)
		return (shade_closest(ray, closest_obj, closest_t, scene));
	return ((t_vec3){0, 0, 0});
}

t_object	*find_closest_object(t_ray ray, t_scene *scene, double *closest_t)
{
	t_object	*obj;
	t_object	*closest_obj;
	double		t;

	*closest_t = INFINITY;
	closest_obj = NULL;
	obj = scene->objects;
	while (obj)
	{
		if (obj->type == SPHERE)
			t = intersect_sphere(ray, obj->sphere);
		else if (obj->type == PLANE)
			t = intersect_plane(ray, obj->plane);
		else if (obj->type == CYLINDER)
			t = intersect_cylinder(ray, obj->cylinder);
		else
			t = -1;
		if (t > 0 && t < *closest_t)
		{
			*closest_t = t;
			closest_obj = obj;
		}
		obj = obj->next;
	}
	return (closest_obj);
}
