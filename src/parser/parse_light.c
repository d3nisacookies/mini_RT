/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaung <akaung@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 15:02:28 by akaung            #+#    #+#             */
/*   Updated: 2026/06/16 15:02:37 by akaung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_RT.h"

void	parse_light(char *line, t_scene *scene)
{
	char	**tokens;

	if (scene->light_set)
		exit_error("multiple lights");
	tokens = ft_split(line, ' ');
	if (!tokens[1] || !tokens[2] || !tokens[3] || tokens[4])
		exit_error("Invalid light params");
	scene->light.position = parse_vector(tokens[1]);
	scene->light.brightness = ft_atof(tokens[2]);
	scene->light.colour = parse_vector(tokens[3]);
	if (scene->light.brightness < 0 || scene->light.brightness > 1)
	{
		free_tokens(tokens);
		exit_error("invalid brightness");
	}
	scene->light_set = 1;
	free_tokens(tokens);
}
