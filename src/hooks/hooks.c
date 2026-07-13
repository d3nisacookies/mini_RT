/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaung <akaung@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:22:56 by akaung            #+#    #+#             */
/*   Updated: 2026/06/16 14:22:56 by akaung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_RT.h"

int	close_window(void *param)
{
	t_app	*app;

	app = (t_app *)param;
	free_scene(app->scene);
	exit(0);
}

int	key_handler(int keycode, void *param)
{
	t_app	*app;

	app = (t_app *)param;
	if (keycode == 65307)
	{
		free_scene(app->scene);
		exit(0);
	}
	return (0);
}
