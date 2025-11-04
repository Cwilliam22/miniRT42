#include "../../include/minirt.h"


// Formules utilisées :
// (équation de la droite)
//      X = Xa + a * t
//      Y = Ya + b * t
//      Z = Za + c * t
// ("équation du cylindre")
// => Equation obtenu en : 
//      1. Projetant le vecteur (point de l'axe - point de l'espace (CP)) 
//          sur la droite (axe du cylindre).
//      2. Soustrayant ce vecteur projeté du vecteur CP (Vnew = CP - Proj).
//      3. Egalant la norme de ce vecteur au rayon du cylindre.
//     
//      (X - Xc)^2 + (Y - Yc)^2 + (Z- Zc)^2 - ((X - Xc)Vx +
//              (Y - Yc)Vy + (Z - Zc)Vz)^2 = r^2
// => Substitution dans l'équation du cylindre
//      A = (a^2 + b^2 + c^2) - (Vx * a + Vy * b + Vz * c)^2
//      B = 2 * [(Xa - Xc)a + (Ya - Yc)b + (Za - Zc)c]
//      C = (Xa - Xc)^2 + (Ya - Yc)^2 + (Za - Zc)^2 -
//              ((Xa - Xc)Vx + (Ya - Yc)Vy + (Za - Zc)Vz)^2 - r^2
// => Formule de Viète
//      Delta = B^2 - 4AC
//      t1, t2 = (-B ± √delta) / 2A
// (Intersections)
//      Xi = Xa + a * ti
//      Yi = Ya + b * ti
//      Zi = Za + c * ti
void get_delta_cylindre(t_scene *scene, t_ray *ray)
{
	ray->hit->inter.x = (ft_sqr(ray->direction.x) + ft_sqr(ray->direction.y) +
		ft_sqr(ray->direction.z)) - ft_sqr(scene->cylinders->axis.x *
        ray->direction.x + scene->cylinders->axis.y * ray->direction.y +
        scene->cylinders->axis.z * ray->direction.z);
	ray->hit->inter.y = 2 * (ray->direction.x * (ray->origin.x -
		scene->cylinders->center.x) + ray->direction.y *
		(ray->origin.y - scene->cylinders->center.y) + ray->direction.z *
		(ray->origin.z - scene->cylinders->center.z));
	ray->hit->inter.z = ft_sqr(ray->origin.x - scene->cylinders->center.x) +
		ft_sqr(ray->origin.y - scene->cylinders->center.y) +
		ft_sqr(ray->origin.z - scene->cylinders->center.z) -
        ft_sqr((ray->origin.x - scene->cylinders->center.x) * scene->cylinders->axis.x +
        (ray->origin.y - scene->cylinders->center.y) * scene->cylinders->axis.y +
        (ray->origin.z - scene->cylinders->center.z) * scene->cylinders->axis.z) -
        ft_sqr(scene->cylinders->radius);
	ray->hit->delta = ft_sqr(ray->hit->inter.y) - 4 * ray->hit->inter.x *
		ray->hit->inter.z;
}

int intersec_cylinder(t_ray *ray, t_scene *scene)
{
    vector_normalize(scene->cylinders->axis);
    get_delta_cylinder(scene, ray);
	if (ray->hit->delta < 0)
		return (0);
	get_color(scene, ray);
	return (1);
}