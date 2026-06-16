/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaung <akaung@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:01:41 by akaung            #+#    #+#             */
/*   Updated: 2026/06/16 13:16:37 by akaung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_RT.h"

void	camera_init(t_camera *cam)
{
	t_vec3	world_up;

	world_up.x = 0;
	world_up.y = 1;
	world_up.z = 0;
	cam->right = vec_normalize(vec_cross(cam->direction, world_up));
	cam->up = vec_normalize(vec_cross(cam->right, cam->direction));
	cam->width = WIDTH;
	cam->height = HEIGHT;
	cam->aspect = (double) WIDTH / HEIGHT;
}

static t_vec3	get_ray_direction(t_camera *cam, double ndc_x, double ndc_y,
					double scale)
{
	t_vec3	horizontal;
	t_vec3	vertical;

	horizontal = vec_scale(cam->right, ndc_x * cam->aspect * scale);
	vertical = vec_scale(cam->up, ndc_y * scale);
	return (vec_normalize(vec_add(vec_add(cam->direction, horizontal),
				vertical)));
}

t_ray	get_camera_ray(t_camera *cam, int px, int py)
{
	t_ray	ray;
	double	ndc_x;
	double	ndc_y;
	double	scale;

	scale = tan(cam->fov * PI / 360.0);
	ndc_x = (2.0 * (px + 0.5) / cam->width) - 1.0;
	ndc_y = 1.0 - (2.0 * (py + 0.5) / cam->height);
	ray.origin = cam->position;
	ray.direction = get_ray_direction(cam, ndc_x, ndc_y, scale);
	return (ray);
}
