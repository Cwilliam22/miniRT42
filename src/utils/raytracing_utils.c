#include "../../include/minirt.h"

// perpendicular vectors have a scalar product = 0
int is_perpendicular(t_vector *v1, t_vector *v2)
{
	if (scalar_product(v1, v2) == 0)
		return (1);
	return (0);
}
