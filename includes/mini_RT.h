/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_RT.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tswe-zin <tswe-zin@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:54:24 by akaung            #+#    #+#             */
/*   Updated: 2026/07/18 22:00:49 by tswe-zin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

/*
** External libraries
*/
# include "../libft/libft.h"
# include "get_next_line.h"
# include "mlx.h"

/*
** System headers
*/
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

/*
** Constants
*/
# define PI 3.14159265358979323846
# define WIDTH 800
# define HEIGHT 600

/*
** Core math types
*/
typedef struct s_vec3
{
	double			x;
	double			y;
	double			z;
}					t_vec3;

typedef struct s_ray
{
	t_vec3			origin;
	t_vec3			direction;
}					t_ray;

/*
** Scene object types
*/

typedef struct s_sphere
{
	t_vec3			center;
	t_vec3			color;
	double			radius;
}					t_sphere;

typedef struct s_plane
{
	t_vec3			point;
	t_vec3			normal;
	t_vec3			color;
}				t_plane;

typedef struct s_cylinder
{
	t_vec3			center;
	t_vec3			axis;
	double			radius;
	double			height;
	t_vec3			color;
}				t_cylinder;

typedef enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER
}					t_obj_type;

typedef struct s_object
{
	t_obj_type		type;
	t_sphere		sphere;
	t_plane			plane;
	t_cylinder		cylinder;
	struct s_object	*next;
}					t_object;

/*
** cylinder
*/

typedef struct s_cyl_hit
{
	t_vec3			top;
	t_vec3			bottom;
	double			body;
	double			cap1;
	double			cap2;
}				t_cyl_hit;

typedef struct s_cyl_quad
{
	t_vec3	oc;
	t_vec3	dp;
	t_vec3	ocp;
	double	a;
	double	b;
	double	c;
	double	d;
}	t_cyl_quad;

/*
** Scene elements
*/
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

/*
** Lighting internals
*/
typedef struct s_hit
{
	t_vec3			p;
	t_vec3			normal;
	t_vec3			light_dir;
	double			light_distance;
	t_vec3			color;
}					t_hit;

typedef struct s_app
{
	void	*mlx;
	void	*win;
	t_scene	*scene;
}	t_app;

/*
** Vector math
*/
t_vec3				vec_add(t_vec3 a, t_vec3 b);
t_vec3				vec_sub(t_vec3 a, t_vec3 b);
t_vec3				vec_scale(t_vec3 v, double t);
t_vec3				vec_normalize(t_vec3 v);
t_vec3				vec_cross(t_vec3 a, t_vec3 b);
double				vec_dot(t_vec3 a, t_vec3 b);
double				vec_length(t_vec3 v);

/*
** Camera
*/
void				camera_init(t_camera *cam);
t_ray				get_camera_ray(t_camera *cam, int px, int py);

/*
** Rendering
*/
void				render(void *mlx, void *win, t_scene *scene);
t_vec3				trace_ray(t_ray ray, t_scene *scene);
t_object			*find_closest_object(t_ray ray, t_scene *scene,
						double *closest_t);
t_vec3				compute_lighting(t_ray ray, t_object *obj,
						double t, t_scene *scene);
int					is_in_shadow(t_vec3 p, t_vec3 light_dir,
						double light_distance, t_scene *scene);
double				intersect_sphere(t_ray ray, t_sphere sphere);
double				intersect_plane(t_ray ray, t_plane plane);
double				intersect_cylinder(t_ray ray, t_cylinder cylinder);
double				intersect_cylinder_body(t_ray ray, t_cylinder cyl);
double				intersect_disk(t_ray ray, t_vec3 center,
						t_vec3 normal, double radius);
double				min_positive(double a, double b);
int					color_to_int(t_vec3 color);
double				clamp(double value, double min, double max);

/*
** Parser
*/
void				parse_scene(char *filename, t_scene *scene);
void				parse_line(char *line, t_scene *scene);
void				parse_ambient(char *line, t_scene *scene);
void				parse_camera(char *line, t_scene *scene);
void				parse_light(char *line, t_scene *scene);
void				parse_sphere(char *line, t_scene *scene);
void				parse_plane(char *line, t_scene *scene);
void				parse_cylinder(char *line, t_scene *scene);
t_vec3				parse_vector(char *str);
void				free_tokens(char **tokens);
void				free_and_exit(char **tokens, t_scene *scene, char *msg);

/*
** Utils
*/
void				scene_init(t_scene *scene);
void				exit_error(char *msg, t_scene *scene);
void				setup_mlx(void **mlx, void **win, t_scene *scene);
void				free_scene(t_scene *scene);

/*
** Hooks
*/
int					key_handler(int keycode, void *param);
int					close_window(void *param);

#endif