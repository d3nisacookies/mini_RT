#include "mini_RT.h"

t_vec3  vec_normalize(t_vec3 v)
{
    double length;
    t_vec3 res;

    length = vec_length(v);
    res.x = v.x / length;
    res.y = v.y / length;
    res.z = v.z / length;
    return (res);
}

t_vec3 vec_cross(t_vec3 a, t_vec3 b)
{
    t_vec3 res;

    res.x = a.y*b.z - a.z * b.y;
    res.y = a.z*b.x - a.x * b.z;
    res.z = a.x*b.y - a.y * b.x;

    return (res);
}

double vec_length(t_vec3 v)
{
    double res;

    res = sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
    return (res);
}