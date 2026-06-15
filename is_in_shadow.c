#include "mini_RT.h"

int is_in_shadow(t_vec3 p, t_vec3 light_direction, double light_distance, t_scene *scene)
{
    t_ray       shadow_ray;
    double      t;
    t_object    *obj;

    shadow_ray.origin = p;
    shadow_ray.direction = light_direction;
    obj = scene->objects;

    while (obj)
    {
        if (obj->type == SPHERE)
        {
            t = intersect_sphere(shadow_ray, obj->sphere);
            if (t > 0 && t < light_distance)
                return (1);
        }
        obj = obj->next;
    }
    return (0);
}