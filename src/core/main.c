#include "../../include/minirt.h"

int	main(int ac, char **av)
{
	t_scene	scene;
	t_ray	ray;
	
	if (!arg_check(ac, av))
		return (1);
	init_scene(&scene);
	if (!parse_scene(av[1], &scene))
	{
		cleanup_scene(&scene);
		return (1);
	}
	if (!validate_scene(&scene))
	{
		cleanup_scene(&scene);
		return (1);
	}
	print_scene_summary(&scene);
	if (!raytracer(&scene, &ray))
	{
		cleanup_scene(&scene);
		return (1);
	}
	cleanup_scene(&scene);
	return (0);
}
