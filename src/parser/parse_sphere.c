/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tswe-zin <tswe-zin@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 15:02:49 by akaung            #+#    #+#             */
/*   Updated: 2026/07/18 21:41:56 by tswe-zin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_RT.h"

void	parse_sphere(char *line, t_scene *scene)
{
	char		**tokens;
	t_object	*obj;

	tokens = ft_split(line, ' ');
	if (!tokens[1] || !tokens[2] || !tokens[3] || tokens[4])
		free_and_exit(tokens, scene, "Invalid sphere");
	obj = malloc(sizeof(t_object));
	if (!obj)
		free_and_exit(tokens, scene, "Malloc failed");
	if (!check_token(tokens[2]))
		free_and_exit(tokens, scene, "Invalid sphere radius");
	obj->type = SPHERE;
	obj->sphere.center = parse_vector(tokens[1], tokens, scene);
	obj->sphere.radius = ft_atof(tokens[2]) / 2.0;
	if (obj->sphere.radius <= 0)
		free_and_exit(tokens, scene, "Invalid sphere radius");
	obj->sphere.color = parse_vector(tokens[3], tokens, scene);
	obj->next = scene->objects;
	scene->objects = obj;
	free_tokens(tokens);
}

void	free_and_exit(char **tokens, t_scene *scene, char *msg)
{
	free_tokens(tokens);
	exit_error(msg, scene);
}
