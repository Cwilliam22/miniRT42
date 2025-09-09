/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 09:43:00 by ktiomico          #+#    #+#             */
/*   Updated: 2025/09/09 14:46:59 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

/* ============ CORE ============ */
t_bool		arg_check(int ac, char **av);
void		print_scene_summary(t_scene *scene);

/* ============ VALIDATION ============ */
void		init_scene(t_scene *scene);
void		cleanup_scene(t_scene *scene);
t_bool		validate_scene(t_scene *scene);
t_bool		is_normalized_vector(t_vector *vec);

/* ============ PARSING ============ */
t_bool		parse_scene(char *filename, t_scene *scene);
t_bool		parse_line(char *line, t_scene *scene);
t_bool		process_lines(int fd, t_scene *scene);
t_bool		identify_element(char **tokens, char *line, t_scene *scene);
t_bool		parse_ambient(char **tokens, t_scene *scene);
t_bool		parse_camera(char **tokens, t_scene *scene);
t_bool		parse_light(char **tokens, t_scene *scene);
t_bool		parse_sphere(char **tokens, t_scene *scene);
t_bool		parse_plane(char **tokens, t_scene *scene);
t_bool		parse_cylinder(char **tokens, t_scene *scene);
t_bool		check_cylinder_token_count(char **tokens);
t_bool		parse_cylinder_geometry(char **tokens, t_cylinder *cyl);
t_cylinder	*allocate_cylinder(t_scene *scene);

/* ============ UTILS ============ */
t_bool		is_valid_double(char *str);
double		parse_double(char *str);
void		free_split(char **split);

/* ============ MATH ============ */
t_bool		parse_vector(char *str, t_vector *vec);
t_bool		parse_color(char *str, t_color *color);

#endif