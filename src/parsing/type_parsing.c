/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:51:00 by ktiomico          #+#    #+#             */
/*   Updated: 2025/09/09 14:51:00 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_bool	parse_vector(char *str, t_vector *vec)
{
	char	**split;

	split = ft_split(str, ',');
	if (!split)
		return (FALSE);
	if (!split[0] || !split[1] || !split[2] || split[3])
	{
		free_split(split);
		return (FALSE);
	}
	vec->x = parse_double(split[0]);
	vec->y = parse_double(split[1]);
	vec->z = parse_double(split[2]);
	free_split(split);
	if (vec->x == -999999.0 || vec->y == -999999.0 || vec->z == -999999.0)
		return (FALSE);
	return (TRUE);
}

static t_bool	validate_color_values(double r, double g, double b)
{
	if (r == -999999.0 || g == -999999.0 || b == -999999.0)
		return (FALSE);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (FALSE);
	return (TRUE);
}

static t_bool	parse_color_components(char *str, double *r, double *g,
		double *b)
{
	char	**split;
	int		len;

	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
	split = ft_split(str, ',');
	if (!split || !split[0] || !split[1] || !split[2] || split[3])
	{
		if (split)
			free_split(split);
		return (FALSE);
	}
	*r = parse_double(split[0]);
	*g = parse_double(split[1]);
	*b = parse_double(split[2]);
	free_split(split);
	return (TRUE);
}

t_bool	parse_color(char *str, t_color *color)
{
	double	r;
	double	g;
	double	b;

	if (!parse_color_components(str, &r, &g, &b))
		return (FALSE);
	if (!validate_color_values(r, g, b))
		return (FALSE);
	color->r = r / 255.0;
	color->g = g / 255.0;
	color->b = b / 255.0;
	return (TRUE);
}
