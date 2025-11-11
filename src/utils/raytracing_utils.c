#include "../../include/minirt.h"

// perpendicular vectors have a scalar product = 0
int is_perpendicular(t_vector v1, t_vector v2)
{
	if (scalar_product(v1, v2) == 0)
		return (1);
	return (0);
}

double ft_sqr(double x)
{
	return (x * x);
}

// Calcul le point d'intersection le plus proche de la caméra
// Prend en compte la position de la caméra dans la scène
// Donne une norme de ces vecteurs pour comparer la distance
t_vector	get_nearest_intersec(t_vector p1, t_vector p2, t_scene *scene)
{
	double	norm1;
	double	norm2;
	t_vector	v1;
	t_vector	v2;

	v1.x = p1.x - scene->camera.position.x;
	v1.y = p1.y - scene->camera.position.y;
	v1.z = p1.z - scene->camera.position.z;
	v2.x = p2.x - scene->camera.position.x;
	v2.y = p2.y - scene->camera.position.y;
	v2.z = p2.z - scene->camera.position.z;
	norm1 = vector_norm(v1);
	norm2 = vector_norm(v2);
	if (norm1 < norm2)
		return (p1);
	else
		return (p2);
}
