#include "../../include/minirt.h"

int init_base_world(t_base_world *base)
{
    base->forward = (t_vector){0, 0, 1};
    base->right = (t_vector){1, 0, 0};
    base->up = (t_vector){0, 1, 0};
    return (1);
}

int make_base_cam(t_scene *scene)
{
    scene->camera.right = vector_normalize(vector_product(scene->camera.forward, scene->base_world.up));
    scene->camera.up = vector_normalize(vector_product(scene->camera.right, scene->camera.forward));
    return (1);
}

int make_orientation_cam(t_scene *scene)
{
    init_base_world(&scene->base_world);
	scene->camera.forward = (t_vector){-1, 0, 0};
    scene->camera.forward = vector_normalize(scene->camera.forward);
    if (!make_base_cam(scene))
        return (0);
    return (1);
}
