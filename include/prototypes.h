/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcapt <wcapt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 09:43:00 by ktiomico          #+#    #+#             */
/*   Updated: 2025/10/03 14:06:43 by wcapt            ###   ########.fr       */
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

/* ============ RAYTRACING ============ */

// calculs.c
int         radian_to_degree(double rad);
int         degree_to_radian(int deg);

// ray_collision.c
int         ray_intersec(double vx, double vy, double vz, t_scene *scene);

// sphere.c
int         intersec_sphere(double vx, double vy, double vz, t_scene *scene);
int         ray_collision_sp();

// plane.c
int         intersec_plane(double vx, double vy, double vz, t_scene *scene);

// cylinder.c
int         intersec_cylinder(double vx, double vy, double vz, t_scene *scene);

// raytracer.c
int         init_mlx(t_scene *scene);
int         init_pixel(t_scene *scene, t_ray *ray);
t_vector    change_base_ray(t_vector v, t_scene *scene);
int         parse_pixel(t_scene *scene, t_ray *ray);
int         raytracer(t_scene *scene, t_ray *ray);

// trigonometry.c
int         viewport_size(t_scene *scene);

// vectors.c
double      scalar_product(t_vector v1, t_vector v2);
t_vector    vector_product(t_vector v1, t_vector v2);
double      vector_norm(t_vector v);
t_vector    vector_scale(t_vector v, double n);
t_vector    vector_normalize(t_vector v);

// camera.c
int         make_base_cam(t_scene *scene);
int         make_orientation_cam(t_scene *scene);

// raytracing_utils.c
int         is_perpendicular(t_vector v1, t_vector v2);


#endif