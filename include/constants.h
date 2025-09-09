/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 09:01:20 by ktiomico          #+#    #+#             */
/*   Updated: 2025/09/09 09:56:48 by ktiomico         ###   ########.fr       */
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
# define ARG_INVALID_PLUS RED"Error: Too many arguments"RESET"\n"
# define ARG_INVALID_MINUS RED"Error: Too few arguments"RESET"\n"
# define ARG_USAGE YELLOW"Usage: ./minirt [file.rt]"RESET"\n"
# define FILE_INVALID RED"Error: Provide a valid file *.rt"RESET"\n"

#endif
