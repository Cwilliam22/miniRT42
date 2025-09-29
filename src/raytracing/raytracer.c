
#include "../../include/minirt.h"

#ifdef __linux__

int init_mlx(t_scene *scene)
{
	scene->mlx = mlx_init();
	if (!scene->mlx)
		return (printf("Error: Impossible to init mlx\n"), 0);
	scene->mlx_win = mlx_new_window(scene->mlx, WIDTH, HEIGHT, "MiniRT");
	if (!scene->mlx_win)
	{
		mlx_destroy_display(scene->mlx);
		free(scene->mlx);
		return (printf("Error: Impossible to create window\n"), 0);
	}
	return (1);
}

#else

int init_mlx(t_scene *scene)
{
	scene->mlx = mlx_init();
	if (!scene->mlx)
		return (printf("Error: Impossible to init mlx\n"), 0);
	scene->mlx_win = mlx_new_window(scene->mlx, WIDTH, HEIGHT, "MiniRT");
	if (!scene->mlx_win)
	{
		free(scene->mlx);
		return (printf("Error: Impossible to create window\n"), 0);
	}
	return (1);
}

#endif

int	init_pixel(t_scene *scene, t_ray *ray)
{
	
	return (1);
}

int parse_pixel(t_scene *scene, t_ray *ray)
{
    int    x;
    int    y;
	double X;
	double Y;
	double Z;

	x = 0;
	y = 0;
    while (x < WIDTH)
    {
        y = 0;
        while (y < HEIGHT)
        {
			// Calculate the direction vector from the camera to the pixel
			// Vx = Bx - Ax
			// Vy = By - Ay
			// Vz = Bz - Az

			// Initialize ray with origin and direction for each pixel
			ray->origin = scene->camera.position;
			// Position pixel with camera's view
            X = -scene->viewport->width  * 0.5 + (x + 0.5) * scene->viewport->px_x;
			Y =  scene->viewport->height * 0.5 - (y + 0.5) * scene->viewport->px_y;
			Z =  scene->camera.viewport;
			// Position pixel with world's view
			ray->direction.x = 0; // Not finished
			ray->direction.y = 0; // *Same
			ray->direction.z = 0; // *Same
            init_pixel(scene, ray);
            y++;
        }
        x++;
    }
    return (1);
}

int raytracer(t_scene *scene, t_ray *ray)
{
	if (!init_mlx(scene))
		return (0);
	if (!parse_pixel(scene, ray))
	{
		mlx_destroy_window(scene->mlx, scene->mlx_win);
		#ifdef __linux__
		mlx_destroy_display(scene->mlx);
		#endif
		free(scene->mlx);
		return (0);
	}
	mlx_loop(scene->mlx);
	return (1);
}
