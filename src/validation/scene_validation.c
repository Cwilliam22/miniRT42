/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:30:00 by ktiomico          #+#    #+#             */
/*   Updated: 2025/09/09 16:30:00 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_bool	validate_scene(t_scene *scene)
{
	if (scene->ambient_count != 1)
	{
		printf("Error: Scene must have exactly 1 ambient lighting (A)\n");
		return (FALSE);
	}
	if (scene->camera_count != 1)
	{
		printf("Error: Scene must have exactly 1 camera (C)\n");
		return (FALSE);
	}
	if (scene->light_count < 1)
	{
		printf("Error: Scene must have at least 1 light (L)\n");
		return (FALSE);
	}
	return (TRUE);
}
