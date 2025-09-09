/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:52:00 by ktiomico          #+#    #+#             */
/*   Updated: 2025/09/09 14:52:00 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_bool	check_cylinder_token_count(char **tokens)
{
	if (!tokens[1] || !tokens[2] || !tokens[3]
		|| !tokens[4] || !tokens[5] || tokens[6])
	{
		printf("Error: Cylinder requires exactly 5 parameters\n");
		return (FALSE);
	}
	return (TRUE);
}

t_bool	parse_cylinder_geometry(char **tokens, t_cylinder *cyl)
{
	if (!parse_vector(tokens[1], &cyl->center)
		|| !parse_vector(tokens[2], &cyl->axis))
	{
		printf("Error: Invalid cylinder center or axis\n");
		return (FALSE);
	}
	if (!is_normalized_vector(&cyl->axis))
	{
		printf("Error: Cylinder axis must be normalized\n");
		return (FALSE);
	}
	cyl->radius = parse_double(tokens[3]);
	cyl->height = parse_double(tokens[4]);
	if (cyl->radius == -999999.0 || cyl->radius <= 0
		|| cyl->height == -999999.0 || cyl->height <= 0)
	{
		printf("Error: Cylinder dimensions must be positive\n");
		return (FALSE);
	}
	return (TRUE);
}

t_cylinder	*allocate_cylinder(t_scene *scene)
{
	t_cylinder	*new_cylinders;

	new_cylinders = realloc(scene->cylinders,
			sizeof(t_cylinder) * (scene->cylinder_count + 1));
	if (!new_cylinders)
	{
		printf("Error: Memory allocation failed\n");
		return (NULL);
	}
	scene->cylinders = new_cylinders;
	return (&scene->cylinders[scene->cylinder_count]);
}
