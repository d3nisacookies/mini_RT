/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaung <akaung@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 15:02:28 by akaung            #+#    #+#             */
/*   Updated: 2026/07/19 23:47:36 by akaung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_RT.h"

void	parse_light(char *line, t_scene *scene)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (scene->light_set)
		free_and_exit(tokens, scene, "Multiple lights");
	if (!tokens[1] || !tokens[2] || !tokens[3] || tokens[4])
		free_and_exit(tokens, scene, "Invalid light params.");
	if (!check_token(tokens[2]))
		free_and_exit(tokens, scene, "Invalid brightness");
	scene->light.position = parse_vector(tokens[1], tokens, scene);
	scene->light.brightness = ft_atof(tokens[2]);
	scene->light.colour = parse_vector(tokens[3], tokens, scene);
	if (scene->light.brightness < 0 || scene->light.brightness > 1)
		free_and_exit(tokens, scene, "Invalid brightness");
	scene->light_set = 1;
	free_tokens(tokens);
}
