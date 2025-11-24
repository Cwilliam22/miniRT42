#include "../../include/minirt.h"

t_color looking_for_color(t_ray *ray, t_scene *scene)
{
    t_color rgb;
    
    rgb = (t_color){0, 0, 0};
    if (ray->hit.object_type == SPHERE)
        rgb = scene->spheres[ray->hit.id].color;
    else if (ray->hit.object_type == PLANE)
        rgb = scene->planes[ray->hit.id].color;
    else if (ray->hit.object_type == CYLINDER)
        rgb = scene->cylinders[ray->hit.id].color;
    return (rgb);
}

int ray_intersec(t_ray *ray, t_scene *scene)
{
    t_color rgb;
    int     color;

    intersec_spheres(ray, scene);
    intersec_planes(ray, scene);
    intersec_cylinders(ray, scene);
    if (ray->hit.hit == TRUE)
    {
        rgb = looking_for_color(ray, scene);
        color = rgb_to_int(rgb);
        mlx_pixel_put(scene->mlx, scene->mlx_win, ray->pixel_x,
            ray->pixel_y, color);
        return (1);
    }
    else
    {
        mlx_pixel_put(scene->mlx, scene->mlx_win, ray->pixel_x,
            ray->pixel_y, 0x000000);
        return (1);
    }
    return (0);
}
