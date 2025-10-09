#include "../../include/minirt.h"

// d = −(a * x0​ + b * y0​ + c * z0​)
// calculate the cst (d)
double value_d(t_vector n, t_vector p)
{
    double  result;

    result = -(n.x * p.x + n.y * p.y + n.z * p.z);
    return (result);
}

int look_at_color(int n)
{
   return (1); 
}

// (Xo, Yo, Zo) = point on the plane
// (a, b, c) = vector normal to the plane
// need to normalize the normal vector
// // x(t) = Xo + t*dx 
// y(t) = Yo + t*dy 
// z(t) = Zo + t*dz 
// ax + by + cz +d = 0
// a(Xo + t*dx) + b(Yo + t*dy) + c(Zo + t*dz) + d = 0
// a*Xo + a*dx*t + b*Yo + b*dy*t + c*Zo + c*dz*t + d = 0
// a*Xo + b*Yo + c*Zo + d = - a*dx*t - b*dy*t - c*dz*t
// -(a*Xo + b*Yo + c*Zo + d) / (a*dx + b*dy + c*dz) = t 
int intersec_plane(t_ray *ray, t_scene *scene)
{
    double  d;
    double  t;
    double  num;
    double  den;
    t_vector intersec;

    num = scene->planes->normal.x * ray->origin.x + scene->planes->normal.y
        * ray->origin.y + scene->planes->normal.z * ray->origin.z + d;
    den = scene->planes->normal.x * ray->direction.x + scene->planes->normal.y
        * ray->direction.y + scene->planes->normal.z * ray->direction.z;
    if (fabs(den) < 1e-12)
        return (0);
    d = value_d(scene->planes->normal, scene->planes->point);
    t = - num / den;
    intersec.x = ray->origin.x + t * ray->direction.x;
    intersec.y = ray->origin.y + t * ray->direction.y;
    intersec.z = ray->origin.z + t * ray->direction.z;
    look_at_color(0);
    return (1);
}
