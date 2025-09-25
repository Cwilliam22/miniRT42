#include "../../include/minirt.h"

int ray_collision_sp()
{
    // L : vecteur de la caméra au centre de la sphère
    // L = C - O
    return (1);
}

int intersec_sphere(double vx, double vy, double vz, t_scene *scene)
{
    int intersec;

    intersec = ray_collision_sp();
    if (intersec == 0)
        return (0);
    else if (intersec == 1)
        return (1);
    else
        return (2);
}