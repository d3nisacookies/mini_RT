#include "mini_RT.h"

t_vec3	parse_vector(char *str)
{
	char **parts;
	t_vec3 v;
	int i;

	parts = ft_split(str, ',');
	v.x = ft_atof(parts[0]);
	v.y = ft_atof(parts[1]);
	v.z = ft_atof(parts[2]);

	i = 0;
	while (parts[i])
	{
		free(parts[i]);
		i++;
	}
	free(parts);
	return (v);
}