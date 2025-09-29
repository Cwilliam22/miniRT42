/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcapt <wcapt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 09:42:53 by ktiomico          #+#    #+#             */
/*   Updated: 2025/09/29 18:22:06 by wcapt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

/* ============ BASIC TYPES ============ */

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

/* ============ MATHEMATICAL STRUCTURES ============ */

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

typedef struct s_ray
{
	t_vector	origin;
	t_vector	direction;
}	t_ray;

/* ============ SCENE ELEMENTS ============ */

typedef struct s_camera
{
	t_vector	position;
	t_vector	orientation;
	double		fov;
	double		viewport;
}	t_camera;

typedef struct s_ambient
{
	double	ratio;
	t_color	color;
}	t_ambient;

typedef struct s_light
{
	t_vector	position;
	double		brightness;
	t_color		color;
}	t_light;

typedef struct s_viewport
{
	double	width;
	double	height;
	double px_x;
	double px_y;

}	t_viewport;

/* ============ HIT ============ */

typedef struct s_hit
{
	t_bool    hit;
    double    delta;
    t_vector  p;
    t_color   color;
    int       object_type;
    void     *object;
}	t_hit;

/* ============ GEOMETRIC OBJECTS ============ */

typedef struct s_sphere
{
	t_vector	center;
	double		radius;
	t_color		color;
}	t_sphere;

typedef struct s_plane
{
	t_vector	point;
	t_vector	normal;
	t_color		color;
}	t_plane;

typedef struct s_cylinder
{
	t_vector	center;
	t_vector	axis;
	double		radius;
	double		height;
	t_color		color;
}	t_cylinder;

/* ============ SCENE CONTAINER ============ */

typedef struct s_scene
{
	t_camera	camera;
	t_ambient	ambient;
	t_light		light;
	t_sphere	*spheres;
	t_plane		*planes;
	t_cylinder	*cylinders;
	t_viewport	*viewport;
	int			ambient_count;
	int			camera_count;
	int			light_count;
	int			sphere_count;
	int			plane_count;
	int			cylinder_count;
	void		*mlx;
	void		*mlx_win;
}	t_scene;

/* ============ PROGRAM DATA ============ */

typedef struct s_data
{
	void	*mlx;
	void	*window;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	t_scene	scene;
}	t_data;

#endif