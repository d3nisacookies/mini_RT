#ifndef MINI_H
# define MINI_H

# include "get_next_line.h"
# include "../libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>

# define PI 3.14159265358979323846
# define WIDTH 800
# define HEIGHT 600

typedef struct s_vec3
{
	double			x;
	double			y;
	double			z;
}					t_vec3;

typedef struct s_sphere
{
	t_vec3			center;
	t_vec3			color;
	double			radius;
}					t_sphere;

typedef struct s_ray
{
	t_vec3			origin;
	t_vec3			direction;
}					t_ray;

typedef struct s_camera
{
	t_vec3			position;
	t_vec3			direction;
	t_vec3			right;
	t_vec3			up;
	double			fov;
	double			aspect;
	int				width;
	int				height;
}					t_camera;

typedef struct s_light
{
	t_vec3			position;
	double			brightness;
	t_vec3			colour;
}					t_light;

typedef struct s_ambient
{
	double			ratio;
	t_vec3			color;
}					t_ambient;

typedef enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER
}					t_obj_type;

typedef struct s_object
{
	t_obj_type		type;
	t_sphere		sphere; /*atar will add more shapes*/
	struct s_object	*next;
}					t_object;

typedef struct s_scene
{
	t_ambient		ambient;
	t_camera		camera;
	t_light			light;
	t_object		*objects;
	int				camera_set;
	int				light_set;
	int				ambient_set;
}					t_scene;

t_vec3				vec_sub(t_vec3 a, t_vec3 b);
t_vec3				vec_add(t_vec3 a, t_vec3 b);
double				vec_dot(t_vec3 a, t_vec3 b);
t_vec3				vec_scale(t_vec3 v, double t);
double				intersect_sphere(t_ray ray, t_sphere sphere);
int					key_handler(int keycode, void *param);
int					close_window(void *param);
double				vec_length(t_vec3 v);
t_vec3				vec_normalize(t_vec3 v);
t_vec3				vec_cross(t_vec3 a, t_vec3 b);
t_ray				get_camera_ray(t_camera *cam, int px, int py);
void				camera_init(t_camera *cam);
t_vec3				compute_lighting(t_ray ray, t_sphere sphere, double t, t_light light,
					t_ambient ambient, t_vec3 object_color, t_scene *scene);
int					color_to_int(t_vec3 color);
void				free_tokens(char **tokens);
void				exit_error(char *msg);
t_vec3				parse_vector(char *str);
void				scene_init(t_scene *scene);
void				parse_cylinder(void);
void 				parse_plane(void);
void				parse_scene(char *filename, t_scene *scene);
void				parse_line(char *line, t_scene *scene);
void    			parse_ambient(char *line, t_scene *scene);
void				parse_camera(char *line, t_scene *scene);
void				parse_light(char *line, t_scene *scene);
void				parse_sphere(char *line, t_scene *scene);
void				render(void *mlx, void *win, t_scene *scene);
t_vec3				trace_ray(t_ray ray, t_scene *scene);
void				scene_init(t_scene *scene);
int					is_in_shadow(t_vec3 p, t_vec3 light_direction, double light_distance, t_scene *scene);

#endif