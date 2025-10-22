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

t_vector	get_nearest_intersec(t_vector p1, t_vector p2)
{
	double	norm1;
	double	norm2;

	norm1 = vector_norm(p1);
	norm2 = vector_norm(p2);
	if (norm1 < norm2)
		return (p1);
	else
		return (p2);
}