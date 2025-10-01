#include "../../include/minirt.h"

// SOHCAHTOA (trigonometry)

// To calculate the viewport size based on the camera's FOV and aspect ratio (WIDTH/HEIGHT)
int viewport_size(t_scene *scene)
{
    double  ratio_asp;
    double  fov_rad;

    fov_rad = degree_to_radian(scene->camera.fov);
    ratio_asp = (double)WIDTH / (double)HEIGHT;
    scene->viewport->width  = 2.0 * scene->camera.d * tan(fov_rad * 0.5);
    scene->viewport->height = scene->viewport->width / ratio_asp;
    scene->viewport->px_x = scene->viewport->width  / (double)WIDTH;
	scene->viewport->px_y = scene->viewport->height / (double)HEIGHT;
    return (1);
}