/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 08:12:30 by ktiomico          #+#    #+#             */
/*   Updated: 2025/09/09 14:34:25 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	main(int ac, char **av)
{
	t_scene	scene;

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
	cleanup_scene(&scene);
	return (0);
}
