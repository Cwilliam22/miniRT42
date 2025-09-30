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
    double u;
    double v;
    double w;
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

// perpendicular vectors have a scalar product = 0
int is_perpendicular(t_vector *v1, t_vector *v2)
{
    if (scalar_product(v1, v2) == 0)
        return (1);
    return (0);
}

int make_orientation_cam(double x, double y, double z)
{

    return (1);
}
