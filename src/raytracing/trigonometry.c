#include "../../include/minirt.h"

// SOHCAHTOA (trigonometry)

// To calculate the viewport size based on the camera's FOV and aspect ratio (WIDTH/HEIGHT)
int viewport_size(t_scene *scene)
{
    double  fov_rad;
    double  height;
    double  length;
    double  ratio_asp;

    height = 2.0 * (tan(fov_rad / 2.00) * scene->camera.viewport);
    ratio_asp = (double)WIDTH / (double)HEIGHT;
    length = ratio_asp * height;
    return (1);
}