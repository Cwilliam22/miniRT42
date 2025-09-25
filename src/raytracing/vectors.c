#include "../../include/minirt.h"

// perpendicular vectors have a dot product = 0
int is_perpendicular(t_vector *v1, t_vector *v2)
{
    double dot_product;

    dot_product = v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
    if (dot_product == 0)
        return (1);
    return (0);
}
