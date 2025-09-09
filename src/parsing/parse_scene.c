/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:45:00 by ktiomico          #+#    #+#             */
/*   Updated: 2025/09/09 14:45:00 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_bool	parse_ambient(char **tokens, t_scene *scene)
{
	if (!tokens[1] || !tokens[2] || tokens[3])
	{
		printf("Error: Ambient requires exactly 2 parameters\n");
		return (FALSE);
	}
	scene->ambient.ratio = parse_double(tokens[1]);
	if (scene->ambient.ratio == -999999.0 || scene->ambient.ratio < 0.0
		|| scene->ambient.ratio > 1.0)
	{
		printf("Error: Ambient ratio must be [0.0,1.0]\n");
		return (FALSE);
	}
	if (!parse_color(tokens[2], &scene->ambient.color))
	{
		printf("Error: Invalid ambient color format\n");
		return (FALSE);
	}
	scene->ambient_count++;
	return (TRUE);
}

static t_bool	validate_light_params(char **tokens, t_scene *scene)
{
	if (!tokens[1] || !tokens[2] || !tokens[3] || tokens[4])
	{
		printf("Error: Light requires exactly 3 parameters\n");
		return (FALSE);
	}
	if (!parse_vector(tokens[1], &scene->light.position))
	{
		printf("Error: Invalid light position\n");
		return (FALSE);
	}
	scene->light.brightness = parse_double(tokens[2]);
	if (scene->light.brightness == -999999.0
		|| scene->light.brightness < 0.0 || scene->light.brightness > 1.0)
	{
		printf("Error: Light brightness must be [0.0,1.0]\n");
		return (FALSE);
	}
	if (!parse_color(tokens[3], &scene->light.color))
	{
		printf("Error: Invalid light color format\n");
		return (FALSE);
	}
	return (TRUE);
}

t_bool	parse_light(char **tokens, t_scene *scene)
{
	if (!validate_light_params(tokens, scene))
		return (FALSE);
	scene->light_count++;
	return (TRUE);
}
