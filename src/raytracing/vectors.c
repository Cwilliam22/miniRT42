#include "../../include/minirt.h"

// scalar_product = 0 if perpendicular
// scalar_product = 1 if collinear and same direction
// scalar_product = -1 if collinear and opposite direction
double scalar_product(t_vector *v1, t_vector *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_vector vector_product(t_vector *v1, t_vector *v2)
{
	t_vector result;

	result.x = (v1->y * v2->z) - (v1->z * v2->y);
	result.y = (v1->z * v2->x) - (v1->x * v2->z);
	result.z = (v1->x * v2->y) - (v1->y * v2->x);
	return (result);
}

double vector_norm(t_vector *v)
{
	return (sqrt(v->x * v->x + v->y * v->y + v->z * v->z));
}

t_vector vector_scale(t_vector v, double n)
{
	t_vector result;

	result.x = v.x * n;
	result.y = v.y * n;
	result.z = v.z * n;
	return (result);
}

t_vector vector_normalize(t_vector *v)
{
	const double small_nb = 1e-12;
	double norm_sqrt;
	t_vector result;
	double invL;

	norm_sqrt = v->x * v->x + v->y * v->y + v->z * v->z;
	if (norm_sqrt < small_nb * small_nb) 
	{
		t_vector zero = {0,0,0};
		return (zero);
	}
	invL = 1.0 / sqrt(norm_sqrt);
	result.x = v->x * invL;
	result.y = v->y * invL;
	result.z = v->z * invL;
	return (result);
}

