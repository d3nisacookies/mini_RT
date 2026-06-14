#include "mini_RT.h"

void render(void *mlx, void *win, t_scene *scene)
{
    int    x;
    int    y;
    t_ray  ray;
    t_vec3 color;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            ray = get_camera_ray(&scene->camera, x, y, WIDTH, HEIGHT);
            color = trace_ray(ray, scene);
            mlx_pixel_put(mlx, win, x, y, color_to_int(color));
            x++;
        }
        y++;
    }
}

t_vec3 trace_ray(t_ray ray, t_scene *scene)
{
    t_object *obj;
    t_object *closest_obj;
    double    closest_t;
    double    t;

    closest_t = INFINITY;
    closest_obj = NULL;
    obj = scene->objects;
    while (obj)
    {
        if (obj->type == SPHERE)
            t = intersect_sphere(ray, obj->sphere);
        else
            t = -1;
        if (t > 0 && t < closest_t)
        {
            closest_t = t;
            closest_obj = obj;
        }
        obj = obj->next;
    }
    if (closest_obj)
        return(compute_lighting(ray, closest_obj->sphere, closest_t, scene->light, scene->ambient, closest_obj->sphere.color));
    else
        return ((t_vec3){0,0,0});
}
