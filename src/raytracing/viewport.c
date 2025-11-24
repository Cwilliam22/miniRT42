#include "../../include/minirt.h"

// SOHCAHTOA (trigonometry)

// To calculate the viewport size based on the camera's FOV and aspect ratio (WIDTH/HEIGHT)
int init_viewport(t_scene *scene)
{
    double  ratio_asp;
    double  fov_rad;

    printf("init_viewport called\n");
    scene->camera.d = 1.0; // Distance from camera to viewport
    fov_rad = degree_to_radian(scene->camera.fov);
    ratio_asp = (double)WIDTH / (double)HEIGHT;
    scene->viewport.width  = 2.0 * scene->camera.d * tan(fov_rad * 0.5);
    scene->viewport.height = scene->viewport.width / ratio_asp;
    scene->viewport.px_x = scene->viewport.width  / (double)WIDTH;
	scene->viewport.px_y = scene->viewport.height / (double)HEIGHT;
    printf("Camera FOV: %f degrees => %.2f radians\n", scene->camera.fov, fov_rad);
    printf("camera d: %.2f\n", scene->camera.d);
    printf("px_x: %.5f, px_y: %.5f\n", scene->viewport.px_x, scene->viewport.px_y);
    return (1);
}