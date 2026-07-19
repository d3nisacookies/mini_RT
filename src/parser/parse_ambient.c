/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaung <akaung@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 15:01:39 by akaung            #+#    #+#             */
/*   Updated: 2026/07/20 00:04:31 by akaung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_RT.h"

void	parse_ambient(char *line, t_scene *scene)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (scene->ambient_set)
		free_and_exit(tokens, scene, "Too many ambients.");
	if (!tokens[1] || !tokens[2] || tokens[3])
		free_and_exit(tokens, scene, "Invalid ambient params.");
	scene->ambient.ratio = ft_atof(tokens[1]);
	if (scene->ambient.ratio < 0 || scene->ambient.ratio > 1)
		free_and_exit(tokens, scene, "Invalid ratio.");
	scene->ambient.color = parse_vector(tokens[2]);
	scene->ambient_set = 1;
	free_tokens(tokens);
}
