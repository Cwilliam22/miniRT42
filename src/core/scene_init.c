/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:30:00 by ktiomico          #+#    #+#             */
/*   Updated: 2025/09/09 16:30:00 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	init_scene(t_scene *scene)
{
	scene->spheres = NULL;
	scene->planes = NULL;
	scene->cylinders = NULL;
	scene->ambient_count = 0;
	scene->camera_count = 0;
	scene->light_count = 0;
	scene->sphere_count = 0;
	scene->plane_count = 0;
	scene->cylinder_count = 0;
}

void	cleanup_scene(t_scene *scene)
{
	if (scene->spheres)
		free(scene->spheres);
	if (scene->planes)
		free(scene->planes);
	if (scene->cylinders)
		free(scene->cylinders);
	scene->spheres = NULL;
	scene->planes = NULL;
	scene->cylinders = NULL;
	scene->sphere_count = 0;
	scene->plane_count = 0;
	scene->cylinder_count = 0;
}
