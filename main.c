#include "mini_RT.h"

int main(int argc, char **argv)
{
    void    *mlx;
    void    *win;
    t_scene scene;
	size_t	len;

    if (argc != 2)
	{
		exit_error("usage: ./miniRT <scene.rt>");
	}
	len = ft_strlen(argv[1]);
	if (len < 3 || ft_strncmp(argv[1] + (len - 3), ".rt", 3) != 0)
    	exit_error("file must have .rt extension");
    scene_init(&scene);
    parse_scene(argv[1], &scene);
    if (!scene.camera_set || !scene.light_set || !scene.ambient_set)
        exit_error("missing required scene element");
    mlx = mlx_init();
    if (!mlx)
        return (1);
    win = mlx_new_window(mlx, WIDTH, HEIGHT, "miniRT");
    if (!win)
	{
        return (1);
	}
	mlx_hook(win, 17, 0, close_window, mlx);
	mlx_key_hook(win, key_handler, mlx);
    render(mlx, win, &scene);
    mlx_loop(mlx);
    return (0);
}
