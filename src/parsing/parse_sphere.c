/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:40:00 by ktiomico          #+#    #+#             */
/*   Updated: 2025/09/09 14:40:00 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static t_bool	validate_sphere_params(char **tokens, t_sphere *sphere)
{
	if (!tokens[1] || !tokens[2] || !tokens[3] || tokens[4])
	{
		printf("Error: Sphere requires exactly 3 parameters\n");
		return (FALSE);
	}
	if (!parse_vector(tokens[1], &sphere->center))
	{
		printf("Error: Invalid sphere center\n");
		return (FALSE);
	}
	sphere->radius = parse_double(tokens[2]);
	if (sphere->radius == -999999.0 || sphere->radius <= 0)
	{
		printf("Error: Sphere radius must be positive\n");
		return (FALSE);
	}
	if (!parse_color(tokens[3], &sphere->color))
	{
		printf("Error: Invalid sphere color\n");
		return (FALSE);
	}
	return (TRUE);
}

t_bool	parse_sphere(char **tokens, t_scene *scene)
{
	t_sphere	*new_spheres;
	t_sphere	*sphere;

	new_spheres = realloc(scene->spheres,
			sizeof(t_sphere) * (scene->sphere_count + 1));
	if (!new_spheres)
	{
		printf("Error: Memory allocation failed\n");
		return (FALSE);
	}
	scene->spheres = new_spheres;
	sphere = &scene->spheres[scene->sphere_count];
	if (!validate_sphere_params(tokens, sphere))
		return (FALSE);
	scene->sphere_count++;
	return (TRUE);
}
