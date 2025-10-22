#include "../../include/minirt.h"

t_vector point_value(t_ray *ray, double t)
{
	t_vector	point;

	point.x = ray->origin.x + ray->direction.x * t;
	point.y = ray->origin.y + ray->direction.y * t;
	point.z = ray->origin.z + ray->direction.z * t;
	return (point);
}

void	get_color(t_ray *ray, t_scene *scene)
{
	double t1;
	double t2;
	t_vector inter1;
	t_vector inter2;

	if (ray->hit->delta == 0)
	{
		t1 = -ray->hit->inter.y / (2 * ray->hit->inter.x);
		return (point_value(ray, t1));
	}
	t1 = (-ray->hit->inter.y + sqrt(ray->hit->delta)) /
		(2 * ray->hit->inter.x);
	t2 = (-ray->hit->inter.y - sqrt(ray->hit->delta)) /
		(2 * ray->hit->inter.x);
	inter1 = point_value(ray, t1);
	inter2 = point_value(ray, t2);
	ray->hit->inter = get_nearest_intersec(inter1, inter2);
}

// Formules utilisées :
// (équation de la droite)
//      X = Xa + a * t
//      Y = Ya + b * t
//      Z = Za + c * t
// (équation de la sphère)
//      (X - Xc)^2 + (Y - Yc)^2 + (Z - Zc)^2 = r^2
// => Substitution dans l'équation de la sphère
//      A = a^2 + b^2 + c^2
//      B = 2 * [a(Xa - Xc) + b(Ya - Yc) + c(Za - Zc)]
//      C = (Xa - Xc)^2 + (Ya - Yc)^2 + (Za - Zc)^2 - r^
// => Formule de Viète
//      Delta = B^2 - 4AC
//      t1, t2 = (-B ± √delta) / 2A
// (Intersections)
//      Xi = Xa + a * ti
//      Yi = Ya + b * ti
//      Zi = Za + c * ti
void get_delta(t_scene *scene, t_ray *ray)
{
	ray->hit->inter.x = ft_sqr(ray->direction.x) + ft_sqr(ray->direction.y) +
		ft_sqr(ray->direction.z);
	ray->hit->inter.y = 2 * (ray->direction.x * (ray->origin.x -
		scene->spheres->center.x) + ray->direction.y *
		(ray->origin.y - scene->spheres->center.y) + ray->direction.z *
		(ray->origin.z - scene->spheres->center.z));
	ray->hit->inter.z = ft_sqr(ray->origin.x - scene->spheres->center.x) +
		ft_sqr(ray->origin.y - scene->spheres->center.y) +
		ft_sqr(ray->origin.z - scene->spheres->center.z) -
		ft_sqr(scene->spheres->radius);
	ray->hit->delta = ft_sqr(ray->hit->inter.y) - 4 * ray->hit->inter.x *
		ray->hit->inter.z;
}

int intersec_sphere(t_ray *ray, t_scene *scene)
{
	get_delta(scene, ray);
	if (ray->hit->delta < 0)
		return (0);
	else
	{
		get_color(scene, ray);
		return (1);
	}
}
