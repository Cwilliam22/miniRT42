#include "../../include/minirt.h"

int intersec_cylinder(t_ray *ray, t_scene *scene)
{
    int intersec;

    intersec = ray_collision_cy();
    if (intersec == 0)
        return (0);
    else if (intersec == 1)
        return (1);
    else
        return (2);
}