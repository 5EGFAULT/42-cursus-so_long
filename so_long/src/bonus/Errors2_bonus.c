/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Errors2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:58:30 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/14 17:58:26 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

void	catch_error_map_border(void)
{
	ft_putstr_fd("Error :\n", 1);
	ft_putstr_fd("ERROR_MAP_BORDER", 1);
	exit(ERROR_MAP_BORDER);
}

void	catch_error_map_player(void)
{
	ft_putstr_fd("Error :\n", 1);
	ft_putstr_fd("ERROR_MAP_PLAYER", 1);
	exit(ERROR_MAP_PLAYER);
}

void	catch_error_map_exit(void)
{
	ft_putstr_fd("Error :\n", 1);
	ft_putstr_fd("ERROR_MAP_EXIT", 1);
	exit(ERROR_MAP_WIDTH);
}

void	catch_error_map_found_forbidden_object(void)
{
	ft_putstr_fd("Error :\n", 1);
	ft_putstr_fd("ERROR_MAP_FOUND_FORBIDDEN_OBJECT", 1);
	exit(ERROR_MAP_FOUND_FORBIDDEN_OBJECT);
}
