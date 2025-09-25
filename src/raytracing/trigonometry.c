#include "../../include/minirt.h"

// SOHCAHTOA (trigonometry)

// To calculate the viewport size based on the camera's FOV and aspect ratio (WIDTH/HEIGHT)
int viewport_size(t_scene *scene)
{
    double  fov_rad;
    double  ratio_asp;

    scene->viewport->height = 2.0 * (tan(fov_rad / 2.00) * scene->camera.viewport);
    ratio_asp = (double)WIDTH / (double)HEIGHT;
    scene->viewport->width = ratio_asp * scene->viewport->height;
    return (1);
}