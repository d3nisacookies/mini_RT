#include "mini_RT.h"

double	clamp(double value, double min, double max)
{
	if (value < min)
		value = min;
	else if (value > max)
		value = max;
	return (value);
}

t_vec3	compute_lighting(t_ray ray, t_sphere sphere, double t, t_light light,
		t_ambient ambient, t_vec3 object_color)
{
	t_vec3	p;
	t_vec3	normal;
	t_vec3	light_dir;
	t_vec3	ambient_term;
	t_vec3	diffuse_term;
	t_vec3	light_total;
	t_vec3	final_color;
	double	diffuse;

	p = vec_add(ray.origin, vec_scale(ray.direction, t));
	normal = vec_normalize(vec_sub(p, sphere.center));
	light_dir = vec_normalize(vec_sub(light.position, p));
	diffuse = vec_dot(normal, light_dir);
	if (diffuse < 0)
		diffuse = 0;
	ambient_term = vec_scale(ambient.color, ambient.ratio);
	diffuse_term = vec_scale(light.colour, (light.brightness * diffuse));
	light_total = vec_add(ambient_term, diffuse_term);
	final_color.x = (object_color.x * light_total.x) / 255.0;
	final_color.y = (object_color.y * light_total.y) / 255.0;
	final_color.z = (object_color.z * light_total.z) / 255.0;
	final_color.x = clamp(final_color.x, 0, 255);
	final_color.y = clamp(final_color.y, 0, 255);
	final_color.z = clamp(final_color.z, 0, 255);
	return (final_color);
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
