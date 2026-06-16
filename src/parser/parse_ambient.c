/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaung <akaung@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 15:01:39 by akaung            #+#    #+#             */
/*   Updated: 2026/06/16 15:01:39 by akaung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_RT.h"

void	parse_ambient(char *line, t_scene *scene)
{
	char	**tokens;

	if (scene->ambient_set)
		exit_error("multiple ambients", scene);
	tokens = ft_split(line, ' ');
	if (!tokens[1] || !tokens[2] || tokens[3])
		exit_error("invalid ambient params", scene);
	scene->ambient.ratio = ft_atof(tokens[1]);
	if (scene->ambient.ratio < 0 || scene->ambient.ratio > 1)
	{
		free_tokens(tokens);
		exit_error("invalid ratio", scene);
	}
	scene->ambient.color = parse_vector(tokens[2]);
	scene->ambient_set = 1;
	free_tokens(tokens);
}
