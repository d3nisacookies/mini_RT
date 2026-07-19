/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tswe-zin <tswe-zin@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 19:46:17 by tswe-zin          #+#    #+#             */
/*   Updated: 2026/07/16 22:43:56 by tswe-zin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_RT.h"

void	parse_cylinder(char *line, t_scene *scene)
{
	char		**tokens;
	t_object	*obj;

	tokens = ft_split(line, ' ');
	if (!tokens[1] || !tokens[2] || !tokens[3] || !tokens[4]
		|| !tokens[5] || tokens[6])
		free_and_exit(tokens, scene, "Invalid cylinder");
	obj = malloc(sizeof(t_object));
	if (!obj)
		free_and_exit(tokens, scene, "Malloc failed");
	if (!check_token(tokens[3]) || !check_token(tokens[4]))
		free_and_exit(tokens, scene, "Invalid cylinder");
	obj->type = CYLINDER;
	obj->cylinder.center = parse_vector(tokens[1], tokens, scene);
	obj->cylinder.axis = vec_normalize(parse_vector(tokens[2], tokens, scene));
	obj->cylinder.radius = ft_atof(tokens[3]) / 2.0;
	obj->cylinder.height = ft_atof(tokens[4]);
	obj->cylinder.color = parse_vector(tokens[5], tokens, scene);
	obj->next = scene->objects;
	scene->objects = obj;
	free_tokens(tokens);
}
