/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tswe-zin <tswe-zin@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 16:22:16 by akaung            #+#    #+#             */
/*   Updated: 2026/07/16 22:39:45 by tswe-zin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_RT.h"

void	parse_plane(char *line, t_scene *scene)
{
	char		**tokens;
	t_object	*obj;

	tokens = ft_split(line, ' ');
	if (!tokens[1] || !tokens[2] || !tokens[3] || tokens[4])
		free_and_exit(tokens, scene, "Invalid plane");
	obj = malloc(sizeof(t_object));
	if (!obj)
		free_and_exit(tokens, scene, "Malloc failed");
	obj->type = PLANE;
	obj->plane.point = parse_vector(tokens[1]);
	obj->plane.normal = vec_normalize(parse_vector(tokens[2]));
	obj->plane.color = parse_vector(tokens[3]);
	obj->next = scene->objects;
	scene->objects = obj;
	free_tokens(tokens);
}
