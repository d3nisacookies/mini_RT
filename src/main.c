/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tswe-zin <tswe-zin@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 11:59:41 by akaung            #+#    #+#             */
/*   Updated: 2026/07/20 08:51:48 by tswe-zin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_RT.h"

static void	validate_args(int ac, char **av)
{
	size_t	len;

	if (ac != 2)
		exit_error("usage: ./miniRT <scene.rt>", NULL);
	len = ft_strlen(av[1]);
	if (len < 3 || ft_strncmp(av[1] + (len - 3), ".rt", 3) != 0)
		exit_error("file must have .rt extenstion.", NULL);
}

void	setup_mlx(t_app	*app)
{
	app->mlx = mlx_init();
	if (!app->mlx)
		mlx_error("mlx init failed", app);
	app->win = mlx_new_window(app->mlx, WIDTH, HEIGHT, "mini_RT");
	if (!app->win)
		mlx_error("mlx new window failed", app);
	app->img.img = mlx_new_image(app->mlx, WIDTH, HEIGHT);
	if (!app->img.img)
		mlx_error("image failed", app);
	app->img.addr = mlx_get_data_addr(app->img.img, &app->img.bpp,
			&app->img.line_len, &app->img.endian);
}

int	main(int argc, char **argv)
{
	t_app		app;
	t_scene		scene;

	validate_args(argc, argv);
	scene_init(&scene);
	parse_scene(argv[1], &scene);
	if (!scene.camera_set || !scene.light_set || !scene.ambient_set)
		exit_error("missing required scene element", &scene);
	app.mlx = NULL;
	app.win = NULL;
	app.img.img = NULL;
	app.scene = &scene;
	setup_mlx(&app);
	mlx_hook(app.win, 17, 0, close_window, &app);
	mlx_key_hook(app.win, key_handler, &app);
	render(&app);
	mlx_loop(app.mlx);
	return (0);
}
