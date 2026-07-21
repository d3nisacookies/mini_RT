/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tswe-zin <tswe-zin@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 15:01:39 by akaung            #+#    #+#             */
/*   Updated: 2026/07/20 10:30:24 by tswe-zin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_RT.h"

t_vec3	parse_color(char *str, char **tokens, t_scene *scene)
{
	t_vec3	color;

	color = parse_vector(str, tokens, scene);
	if (color.x < 0 || color.x > 255
		|| color.y < 0 || color.y > 255
		|| color.z < 0 || color.z > 255)
		free_and_exit(tokens, scene, "Invalid RGB color.");
	return (color);
}

void	parse_ambient(char *line, t_scene *scene)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (scene->ambient_set)
		free_and_exit(tokens, scene, "Too many ambients.");
	if (!tokens[1] || !tokens[2] || tokens[3])
		free_and_exit(tokens, scene, "Invalid ambient params.");
	if (!check_token(tokens[1]))
		free_and_exit(tokens, scene, "Invalid ambient ratio.");
	scene->ambient.ratio = ft_atof(tokens[1]);
	if (scene->ambient.ratio < 0 || scene->ambient.ratio > 1)
		free_and_exit(tokens, scene, "Invalid ratio.");
	scene->ambient.color = parse_color(tokens[2], tokens, scene);
	scene->ambient_set = 1;
	free_tokens(tokens);
}
