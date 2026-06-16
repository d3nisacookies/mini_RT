/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaung <akaung@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 15:02:49 by akaung            #+#    #+#             */
/*   Updated: 2026/06/16 15:02:50 by akaung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_RT.h"

void	parse_sphere(char *line, t_scene *scene)
{
	char		**tokens;
	t_object	*obj;

	tokens = ft_split(line, ' ');
	if (!tokens[1] || !tokens[2] || !tokens[3] || tokens[4])
		exit_error("Invalid sphere");
	obj = malloc(sizeof(t_object));
	if (!obj)
		exit_error("malloc failed");
	obj->type = SPHERE;
	obj->sphere.center = parse_vector(tokens[1]);
	obj->sphere.radius = ft_atof(tokens[2]) / 2.0;
	if (obj->sphere.radius <= 0)
	{
		exit_error("Invalid sphere radius");
		free_tokens(tokens);
	}
	obj->sphere.color = parse_vector(tokens[3]);
	obj->next = scene->objects;
	scene->objects = obj;
	free_tokens(tokens);
}
