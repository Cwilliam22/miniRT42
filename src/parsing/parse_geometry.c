/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane_cylinder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:41:00 by ktiomico          #+#    #+#             */
/*   Updated: 2025/09/09 14:41:00 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static t_bool	validate_plane_params(char **tokens, t_plane *plane)
{
	if (!tokens[1] || !tokens[2] || !tokens[3] || tokens[4])
	{
		printf("Error: Plane requires exactly 3 parameters\n");
		return (FALSE);
	}
	if (!parse_vector(tokens[1], &plane->point)
		|| !parse_vector(tokens[2], &plane->normal)
		|| !parse_color(tokens[3], &plane->color))
	{
		printf("Error: Invalid plane parameters\n");
		return (FALSE);
	}
	if (!is_normalized_vector(&plane->normal))
	{
		printf("Error: Plane normal must be normalized\n");
		return (FALSE);
	}
	return (TRUE);
}

t_bool	parse_plane(char **tokens, t_scene *scene)
{
	t_plane	*new_planes;
	t_plane	*plane;

	new_planes = realloc(scene->planes,
			sizeof(t_plane) * (scene->plane_count + 1));
	if (!new_planes)
	{
		printf("Error: Memory allocation failed\n");
		return (FALSE);
	}
	scene->planes = new_planes;
	plane = &scene->planes[scene->plane_count];
	if (!validate_plane_params(tokens, plane))
		return (FALSE);
	scene->plane_count++;
	return (TRUE);
}

static t_bool	validate_cylinder_params(char **tokens, t_cylinder *cyl)
{
	if (!check_cylinder_token_count(tokens))
		return (FALSE);
	if (!parse_cylinder_geometry(tokens, cyl))
		return (FALSE);
	if (!parse_color(tokens[5], &cyl->color))
	{
		printf("Error: Invalid cylinder color\n");
		return (FALSE);
	}
	return (TRUE);
}

t_bool	parse_cylinder(char **tokens, t_scene *scene)
{
	t_cylinder	*cylinder;

	cylinder = allocate_cylinder(scene);
	if (!cylinder)
		return (FALSE);
	if (!validate_cylinder_params(tokens, cylinder))
		return (FALSE);
	scene->cylinder_count++;
	return (TRUE);
}
