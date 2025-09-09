/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 09:12:54 by ktiomico          #+#    #+#             */
/*   Updated: 2025/09/09 09:56:30 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	arg_check(int ac, char **av)
{
	if (ac < 2)
	{
		write(2, ARG_INVALID_MINUS, ft_strlen(ARG_INVALID_MINUS));
		write(2, ARG_USAGE, ft_strlen(ARG_USAGE));
		return (FALSE);
	}
	else if (ac > 2)
	{
		write(2, ARG_INVALID_PLUS, ft_strlen(ARG_INVALID_PLUS));
		write(2, ARG_USAGE, ft_strlen(ARG_USAGE));
		return (FALSE);
	}
	if (!check_rt_extension(av[1]))
	{
		write(2, FILE_INVALID, ft_strlen(FILE_INVALID));
		return (FALSE);
	}
	return (TRUE);
}

t_bool	check_rt_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 3)
		return (FALSE);
	return (ft_strcmp(filename + len - 3, ".rt") == 0);
}
