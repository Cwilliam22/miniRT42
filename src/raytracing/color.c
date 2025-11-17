#include "../../include/minirt.h"

// RGB to integer conversion
// R -> bits 16-23
// G -> bits 8-15
// B -> bits 0-7
int rgb_to_int(t_color color)
{
    return (((int)color.r << 16) | ((int)color.g << 8) | (int)color.b);
}