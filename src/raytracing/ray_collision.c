#include "../../include/minirt.h"

int ray_intersec(double vx, double vy, double vz, t_scene *scene)
{
    if (!ray_sphere(vx, vy, vz, scene))
        return (0);
    if (!ray_plane(vx, vy, vz, scene))
        return (0);
    if (!ray_cylinder(vx, vy, vz, scene))
        return (0);
    return (1);
}