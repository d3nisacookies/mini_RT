#include "mini_RT.h"

void	camera_init(t_camera *cam)
{
	t_vec3	world_up;

	world_up.x = 0;
	world_up.y = 1;
	world_up.z = 0;
	cam->right = vec_normalize(vec_cross(cam->direction, world_up));
	cam->up = vec_normalize(vec_cross(cam->right, cam->direction));
}

t_ray	get_camera_ray(t_camera *cam, int px, int py, int width, int height)
{
	t_ray ray;
	double ndc_x;
	double ndc_y;
	t_vec3 horizontal;
	t_vec3 vertical;
	t_vec3 ray_direction;
	double aspect;
	double scale;
	double fov_rad;

	fov_rad = cam->fov * PI / 180;
	scale = tan(fov_rad / 2.0);
	aspect = (double)width / height;

	ndc_x = (2.0 * (px + 0.5) / width) - 1.0;
	ndc_y = 1.0 - (2.0 * (py + 0.5) / height);
	horizontal = vec_scale(cam->right, ndc_x * aspect * scale);
	vertical = vec_scale(cam->up, ndc_y * scale);
	ray_direction = vec_normalize(vec_add(vec_add(cam->direction, horizontal),
				vertical));
	ray.origin = cam->position;
	ray.direction = ray_direction;
	return (ray);
}