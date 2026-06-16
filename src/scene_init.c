/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaung <akaung@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 12:15:33 by akaung            #+#    #+#             */
/*   Updated: 2026/06/16 12:15:33 by akaung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_RT.h"

void	scene_init(t_scene *scene)
{
	scene->camera_set = 0;
	scene->ambient_set = 0;
	scene->light_set = 0;
	scene->objects = NULL;
}
