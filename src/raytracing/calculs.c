#include "../../include/minirt.h"

// radians = degrees × (π/180°)
double radian_to_degree(double rad)
{
    return ((int)(rad * (180.0 / M_PI)));
}

// degrees = radians × (180°/π)
double degree_to_radian(int deg)
{
    return ((double)(deg * (M_PI / 180.0)));
}
