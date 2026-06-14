#include "mini_RT.h"

int	main(void)
{
	void *mlx;
	void *win;
	t_camera cam;
	t_sphere sphere;
	t_light light;
	t_ambient ambient;
	t_ray ray;
	t_vec3 color;
	double t;

	mlx = mlx_init();
	if (!mlx)
		return (1);

	win = mlx_new_window(mlx, WIDTH, HEIGHT, "miniRT");
	if (!win)
		return (1);

	cam.position = (t_vec3){0, 0, -5};
	cam.direction = (t_vec3){0, 0, 1};
	cam.fov = 70;
	camera_init(&cam);

	sphere.center = (t_vec3){0, 0, 0};
	sphere.radius = 1.0;
	sphere.color = (t_vec3){255, 0, 0};

	light.position = (t_vec3){2, 2, -3};
	light.colour = (t_vec3){255, 255, 255};
	light.brightness = 1.0;

	ambient.color = (t_vec3){255, 255, 255};
	ambient.ratio = 0.2;

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			ray = get_camera_ray(&cam, x, y, WIDTH, HEIGHT);
			t = intersect_sphere(ray, sphere);

			if (t > 0)
			{
				color = compute_lighting(ray, sphere, t, light, ambient,
						sphere.color);
				mlx_pixel_put(mlx, win, x, y, color_to_int(color));
			}
			else
				mlx_pixel_put(mlx, win, x, y, 0x000000);
		}
	}

	mlx_loop(mlx);
	return (0);
}