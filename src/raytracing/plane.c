#include "../../include/minirt.h"

// Cas d'intersections possible :
// 1) Traverse le plan en un point
// 2) Ne traverse pas le plan (parallèle au plan)
// 3) A une infinité de point d'intersection (droite et plan confondus)

// d = −(a * Xo​ + b * Yo​ + c * Zo​)
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
// x(t) = Xo + t * dx 
// y(t) = Yo + t * dy 
// z(t) = Zo + t * dz 
// ax + by + cz +d = 0
// a(Xo + t * dx) + b(Yo + t * dy) + c(Zo + t * dz) + d = 0
// a * Xo + a * dx * t + b * Yo + b * dy * t + c * Zo + c * dz * t + d = 0
// a * Xo + b * Yo + c * Zo + d = - a * dx * t - b * dy * t - c * dz * t
// -(a * Xo + b * Yo + c * Zo + d) / (a * dx + b * dy + c * dz) = t 
int intersec_plane(t_ray *ray, t_scene *scene)
{
    double  t;
    double  num;
    double  den;
    t_vector intersec;

    // Vérifier if plane est confondu avec la droite (ray)
    scene->planes->d = value_d(scene->planes->normal, scene->planes->point);
    num = scalar_product(scene->planes->normal, ray->origin) + scene->planes->d;
    den = scalar_product(scene->planes->normal, ray->direction);
    if (fabs(den) < 1e-12)
        return (0);
    t = - num / den;
    intersec.x = ray->origin.x + t * ray->direction.x;
    intersec.y = ray->origin.y + t * ray->direction.y;
    intersec.z = ray->origin.z + t * ray->direction.z;
    look_at_color(0);
    return (1);
}


// den = N * D
// N -> vecteur normal au plan
// D -> droite (ray)
// produit scalaire égale à 0 => parallèle