#include "../../include/minirt.h"

int ray_intersec(t_ray *ray, t_scene *scene)
{
    if (!ray_sphere(ray, scene))
        return (0);
    if (!ray_plane(ray, scene))
        return (0);
    if (!ray_cylinder(ray, scene))
        return (0);
    return (1);
}