#include "../../include/minirt.h"

int make_base_cam(t_scene *scene)
{
    return (1);
}

int make_orientation_cam(t_scene *scene)
{
	scene->camera.orientation.x = -1;
    scene->camera.orientation.y = 0;
    scene->camera.orientation.z = 0;
    make_base_cam(scene);
    return (1);
}
