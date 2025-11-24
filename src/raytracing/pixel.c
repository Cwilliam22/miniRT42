#include "../../include/minirt.h"

int parse_pixel(t_scene *scene, t_ray *ray)
{
    int    x;
    int    y;
	double u;
	double v;
	double w;

	x = 0;
	y = 0;
    while (x < WIDTH)
    {
        y = 0;
        while (y < HEIGHT)
        {
			// Initialize ray with origin and direction for each pixel
			ray->origin = scene->camera.position;
			// Position pixel with camera's view
            printf("------------------------------------------------\n");
            printf("width: %.2f, height: %.2f, px_x: %.2f, px_y: %.2f\n",
                scene->viewport.width, scene->viewport.height,
                scene->viewport.px_x, scene->viewport.px_y);
            printf("------------------------------------------------\n");
            u = -scene->viewport.width  * 0.5 + (x + 0.5) * scene->viewport.px_x;
			v =  scene->viewport.height * 0.5 - (y + 0.5) * scene->viewport.px_y;
			w =  scene->camera.d;
			// Position pixel with world's view
            //printf("------------------------------------------------\n");
            //printf("u: %.2f, v: %.2f, w: %.2f\n", u, v, w);
            //printf("------------------------------------------------\n");
			ray->direction = vector_normalize(change_base_ray((t_vector){u, v, w}, scene));
			ray->pixel_x = x;
			ray->pixel_y = y;
			printf("Pixel [%d, %d] => Direction (%.2f, %.2f, %.2f)\n", x, y, ray->direction.x, ray->direction.y, ray->direction.z);
			init_ray(ray, scene->camera.position, ray->direction);
            ray_intersec(ray, scene);
            y++;
        }
        x++;
    }
    return (1);
}
