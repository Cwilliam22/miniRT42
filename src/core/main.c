/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcapt <wcapt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 08:12:30 by ktiomico          #+#    #+#             */
/*   Updated: 2025/09/25 14:17:51 by wcapt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
