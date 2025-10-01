#include "../../include/minirt.h"

int make_base_cam(t_scene *scene)
{
    return (1);
}

int make_orientation_cam(t_scene *scene)
{
	scene->camera.forward.x = -1;
    scene->camera.forward.y = 0;
    scene->camera.forward.z = 0;
    make_base_cam(scene);
    return (1);
}
