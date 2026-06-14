#include "mini_RT.h"

void	parse_scene(char **filename, t_scene *scene)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_error("cannot open file");
	while ((line = get_next_line(fd)) != NULL)
	{
		parse_line(line, scene);
		free(line);
	}
	close(fd);
}

void	parse_line(char *line, t_scene *scene)
{
	if (!strncmp(line, "A", 1))
		parse_ambient(line, scene);
	else if (!strncmp(line, "C", 1))
		parse_camera(line, scene);
	else if (!strncmp(line, "L", 1))
		parse_light(line, scene);
	else if (!strncmp(line, "sp", 2))
		parse_sphere(line, scene);
	else if (!strncmp(line, "pl", 2))
		parse_plane(line, scene);
	else if (!strncmp(line, "cy", 2))
		parse_cylinder(line, scene);
}
