/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaung <akaung@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 15:01:51 by akaung            #+#    #+#             */
/*   Updated: 2026/06/16 15:02:16 by akaung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_RT.h"

void	parse_camera(char *line, t_scene *scene)
{
	char	**tokens;

	if (scene->camera_set)
		exit_error("Multiple cameras");
	tokens = ft_split(line, ' ');
	if (!tokens[1] || !tokens[2] || !tokens[3])
		exit_error("Invalid camera params");
	scene->camera.position = parse_vector(tokens[1]);
	scene->camera.direction = parse_vector(tokens[2]);
	scene->camera.fov = ft_atof(tokens[3]);
	if (scene->camera.fov < 0 || scene->camera.fov > 180)
		exit_error("Invalid FOV");
	camera_init(&scene->camera);
	scene->camera_set = 1;
	free_tokens(tokens);
}
