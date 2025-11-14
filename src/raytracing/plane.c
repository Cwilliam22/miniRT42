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
int intersec_planes(t_ray *ray, t_scene *scene)
{
    double  t;
    double  num;
    double  den;
    t_vector inter;
    t_vector	actual_nearest_point;
    int     i;

    i = 0;
    // Vérifier if plane est confondu avec la droite (ray)
    actual_nearest_point = ray->hit->inter;
    while (i < scene->plane_count)
    {
        scene->planes[i].d = value_d(scene->planes[i].normal, scene->planes[i].point);
        num = scalar_product(scene->planes[i].normal, ray->origin) + scene->planes[i].d;
        den = scalar_product(scene->planes[i].normal, ray->direction);
        if (fabs(den) < 1e-12)
            continue; // parallel to the plane
        t = - num / den;
        ray->hit->inter = point_value(ray, t);
        if (ray->hit->inter.x != actual_nearest_point.x &&
			ray->hit->inter.y != actual_nearest_point.y &&
			ray->hit->inter.z != actual_nearest_point.z)
		{
			ray->hit->object = (void *)scene->planes;
			ray->hit->id = i;
            // send norme btw camera and intersection point for shapes
		}
		i++;
    }
    return (1);
}


// den = N * D
// N -> vecteur normal au plan
// D -> droite (ray)
// produit scalaire égale à 0 => parallèle