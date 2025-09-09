/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:45:00 by ktiomico          #+#    #+#             */
/*   Updated: 2025/09/09 15:45:00 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static t_bool	validate_camera_vectors(char **tokens, t_scene *scene)
{
	if (!parse_vector(tokens[1], &scene->camera.position))
	{
		printf("Error: Invalid camera position\n");
		return (FALSE);
	}
	if (!parse_vector(tokens[2], &scene->camera.orientation))
	{
		printf("Error: Invalid camera orientation\n");
		return (FALSE);
	}
	if (!is_normalized_vector(&scene->camera.orientation))
	{
		printf("Error: Camera orientation must be normalized\n");
		return (FALSE);
	}
	return (TRUE);
}

static t_bool	validate_camera_params(char **tokens, t_scene *scene)
{
	if (!tokens[1] || !tokens[2] || !tokens[3] || tokens[4])
	{
		printf("Error: Camera requires exactly 3 parameters\n");
		return (FALSE);
	}
	if (!validate_camera_vectors(tokens, scene))
		return (FALSE);
	scene->camera.fov = parse_double(tokens[3]);
	if (scene->camera.fov == -999999.0 || scene->camera.fov < 0
		|| scene->camera.fov > 180)
	{
		printf("Error: Camera FOV must be [0,180]\n");
		return (FALSE);
	}
	return (TRUE);
}

t_bool	parse_camera(char **tokens, t_scene *scene)
{
	if (!validate_camera_params(tokens, scene))
		return (FALSE);
	scene->camera_count++;
	return (TRUE);
}
