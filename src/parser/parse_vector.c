/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaung <akaung@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 15:03:13 by akaung            #+#    #+#             */
/*   Updated: 2026/06/16 15:03:30 by akaung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_RT.h"

t_vec3	parse_vector(char *str, char **tokens, t_scene *scene)
{
	char	**parts;
	t_vec3	v;

	parts = ft_split(str, ',');
	if (!parts[0] || !parts[1] || !parts[2] || parts[3]
		|| !check_token(parts[0]) || !check_token(parts[1])
		|| !check_token(parts[2]))
	{
		free_tokens(parts);
		free_and_exit(tokens, scene, "Invalid vector format.");
	}
	v.x = ft_atof(parts[0]);
	v.y = ft_atof(parts[1]);
	v.z = ft_atof(parts[2]);
	free_tokens(parts);
	return (v);
}
