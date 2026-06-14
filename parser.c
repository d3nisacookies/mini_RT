#include "mini_RT.h"

void	parse_scene(char *filename, t_scene *scene)
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
	if (!ft_strncmp(line, "A", 1))
		parse_ambient(line, scene);
	else if (!ft_strncmp(line, "C", 1))
		parse_camera(line, scene);
	else if (!ft_strncmp(line, "L", 1))
		parse_light(line, scene);
	else if (!ft_strncmp(line, "sp", 2))
		parse_sphere(line, scene);
	else if (!ft_strncmp(line, "pl", 2))
		parse_plane();
	else if (!ft_strncmp(line, "cy", 2))
		parse_cylinder();
}

void	exit_error(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void parse_plane(void)
{
	return ;
}

void parse_cylinder(void)
{
	return ;
}
