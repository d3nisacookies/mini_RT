#include "mini_RT.h"

void scene_init(t_scene *scene)
{
    scene->camera_set = 0;
    scene->ambient_set = 0;
    scene->light_set = 0;
    scene->objects = NULL;
}