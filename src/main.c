/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaung <akaung@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 11:59:41 by akaung            #+#    #+#             */
/*   Updated: 2026/06/16 16:10:03 by akaung           ###   ########.fr       */
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

void	setup_mlx(void **mlx, void **win, t_scene *scene)
{
	*mlx = mlx_init();
	if (!*mlx)
		exit_error("mlx init failed", scene);
	*win = mlx_new_window(*mlx, WIDTH, HEIGHT, "mini_RT");
	if (!*win)
		exit_error("mlx new window failed", scene);
}

int	main(int argc, char **argv)
{
	void		*mlx;
	void		*win;
	t_scene		scene;
	t_app		app;

	validate_args(argc, argv);
	scene_init(&scene);
	parse_scene(argv[1], &scene);
	if (!scene.camera_set || !scene.light_set || !scene.ambient_set)
		exit_error("missing required scene element", &scene);
	setup_mlx(&mlx, &win, &scene);
	app.mlx = mlx;
	app.win = win;
	app.scene = &scene;
	mlx_hook(win, 17, 0, close_window, &app);
	mlx_key_hook(win, key_handler, &app);
	render(mlx, win, &scene);
	mlx_loop(mlx);
	return (0);
}
