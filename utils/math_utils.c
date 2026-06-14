#include "../mini_RT.h"

t_vec3	vec_sub(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	return (result);
}

double	vec_dot(t_vec3 a, t_vec3 b)
{
	double	result;

	result = a.x * b.x + a.y * b.y + a.z * b.z;
	return (result);
}

t_vec3	vec_scale(t_vec3 v, double t)
{
	t_vec3	result;

	result.x = v.x * t;
	result.y = v.y * t;
	result.z = v.z * t;
	return (result);
}

t_vec3	vec_add(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	return (result);
}

double	intersect_sphere(t_ray ray, t_sphere sphere)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	t;

	oc = vec_sub(ray.origin, sphere.center);
	a = vec_dot(ray.direction, ray.direction);
	b = 2 * (vec_dot(ray.direction, oc));
	c = (vec_dot(oc, oc) - (sphere.radius * sphere.radius));
	discriminant = (b * b) - (4 * a * c);
	if (discriminant < 0)
		return (-1);
	t = (-b - sqrt(discriminant)) / (2 * a);
	if (t < 0)
	{
		t = (-b + sqrt(discriminant)) / (2 * a);
		if (t < 0)
			return (-1);
	}
	return (t);
}

double	ft_atof(const char *nptr)
{
	double	result;
	int		sign;
	double	divider;

	result = 0.0;
	sign = 1;
	if (*nptr == '-')
	{
		sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
		result = result * 10.0 + (*nptr++ - '0');
	if (*nptr == '.')
	{
		nptr++;
		divider = 10.0;
		while (*nptr >= '0' && *nptr <= '9')
		{
			result += (*nptr++ - '0') / divider;
			divider *= 10.0;
		}
	}
	return (result * sign);
}
