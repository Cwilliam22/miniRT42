/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:06:21 by ktiomico          #+#    #+#             */
/*   Updated: 2025/09/09 14:21:34 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_bool	identify_element(char **tokens, char *line, t_scene *scene)
{
	if (ft_strncmp(tokens[0], "A", 2) == 0)
		return (parse_ambient(tokens, scene));
	else if (ft_strncmp(tokens[0], "C", 2) == 0)
		return (parse_camera(tokens, scene));
	else if (ft_strncmp(tokens[0], "L", 2) == 0)
		return (parse_light(tokens, scene));
	else if (ft_strncmp(tokens[0], "sp", 3) == 0)
		return (parse_sphere(tokens, scene));
	else if (ft_strncmp(tokens[0], "pl", 3) == 0)
		return (parse_plane(tokens, scene));
	else if (ft_strncmp(tokens[0], "cy", 3) == 0)
		return (parse_cylinder(tokens, scene));
	else
	{
		printf("Unknown element: %s", tokens[0]);
		return (FALSE);
	}
	(void)line;
	(void)scene;
	return (TRUE);
}

t_bool	parse_line(char *line, t_scene *scene)
{
	char	**tokens;
	t_bool	result;
	int		len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	tokens = ft_split(line, ' ');
	if (!tokens || !tokens[0])
	{
		if (tokens)
			free_split(tokens);
		return (FALSE);
	}
	result = identify_element(tokens, line, scene);
	free_split(tokens);
	return (result);
}

t_bool	process_lines(int fd, t_scene *scene)
{
	char	*line;
	int		line_num;

	line_num = 1;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_strlen(line) > 1 && line[0] != '\n' && line[0] != '#')
		{
			if (!parse_line(line, scene))
			{
				printf("Error parsing line %d: %s", line_num, line);
				free(line);
				return (FALSE);
			}
		}
		free(line);
		line = get_next_line(fd);
		line_num++;
	}
	return (TRUE);
}

t_bool	parse_scene(char *filename, t_scene *scene)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: Cannot open file '%s'\n", filename);
		return (FALSE);
	}
	if (!process_lines(fd, scene))
	{
		printf("Error: Failed to parse file '%s'\n", filename);
		close(fd);
		return (FALSE);
	}
	close(fd);
	return (TRUE);
}
