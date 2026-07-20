/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tswe-zin <tswe-zin@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:22:56 by akaung            #+#    #+#             */
/*   Updated: 2026/07/20 08:48:22 by tswe-zin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_RT.h"

void	mlx_error(char *msg, t_app *app)
{
	destroy_mlx(app);

	if (app->scene)
		free_scene(app->scene);

	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void	destroy_mlx(t_app *app)
{
	if (app->img.img)
		mlx_destroy_image(app->mlx, app->img.img);
	if (app->win)
		mlx_destroy_window(app->mlx, app->win);
	if (app->mlx)
	{
		mlx_destroy_display(app->mlx);
		free(app->mlx);
	}
}

int	close_window(void *param)
{
	t_app	*app;

	app = (t_app *)param;
	destroy_mlx(app);
	if (app->scene)
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
