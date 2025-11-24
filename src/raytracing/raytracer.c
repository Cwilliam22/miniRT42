
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

/*
int	init_pixel(t_scene *scene, t_ray *ray)
{
	return (1);
}
*/

// linear combination
// Dmonde = Pmonde - Ocam = X * right + Y * up + Z * forward
// (Dx, Dy, Dz) = X (Rx, Ry, Rz) + Y (Ux, Uy, Uz) + Z (Fx, Fy, Fz)
// Dx = X * right.x + Y * up.x + Z * forward.x
// Dy = X * right.y + Y * up.y + Z * forward.y
// Dz = X * right.z + Y * up.z + Z * forward.z
t_vector change_base_ray(t_vector v, t_scene *scene)
{
	t_vector result;
	t_camera cam;

	cam = scene->camera;
	result.x = v.x * cam.right.x + v.y * cam.up.x + v.z * cam.forward.x;
	result.y = v.x * cam.right.y + v.y * cam.up.y + v.z * cam.forward.y;
	result.z = v.x * cam.right.z + v.y * cam.up.z + v.z * cam.forward.z;
	return (result);
}

int raytracer(t_scene *scene, t_ray *ray)
{
	if (!init_mlx(scene))
		return (0);
	if (!make_orientation_cam(scene))
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
