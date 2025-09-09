/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 09:01:20 by ktiomico          #+#    #+#             */
/*   Updated: 2025/09/09 10:14:43 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

/* Macros for colors */
# define BLACK	"\e[30m"
# define RED	"\e[31m"
# define GREEN  "\e[32m"
# define YELLOW "\e[33m"
# define BLUE   "\e[34m"
# define PURPLE "\e[35m"
# define CYAN   "\e[36m"
# define WHITE  "\e[37m"
# define RESET  "\e[0m"

/* Macros for int */
# define ARG_CHECK 2
# define ERROR 1

/* Macros for strings */
# define ARG_INVALID_PLUS "\e[31mError: Too many arguments\e[0m\n"
# define ARG_INVALID_MINUS "\e[31mError: Too few arguments\e[0m\n"
# define ARG_USAGE "\e[33mUsage: ./minirt [file.rt]\e[0m\n"
# define FILE_INVALID "\e[31mError: Provide a valid file *.rt\e[0m\n"

#endif
