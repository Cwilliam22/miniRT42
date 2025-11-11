#include "../../include/minirt.h"

int ray_intersec(t_ray *ray, t_scene *scene)
{
    if (!intersec_sphere(ray, scene))
        return (0);
    if (!intersec_plane(ray, scene))
        return (0);
    if (!intersec_cylinder(ray, scene))
        return (0);
    else
    // print un pixel dans la couleur du fond (noir)
    return (1);
}