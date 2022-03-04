/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:08:51 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/04 12:24:46 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	catch_error_map_not_found(void)
{
	ft_putstr_fd("Error :\n", 1);
	ft_putstr_fd("ERROR_MAP_NOT_FOUND", 1);
	exit(ERROR_MAP_NOT_FOUND);
}

void	catch_error_map_not_valid(void)
{
	ft_putstr_fd("Error :\n", 1);
	ft_putstr_fd("ERROR_MAP_NOT_VALID", 1);
	exit(ERROR_MAP_NOT_VALID);
}

void	catch_error_map_not_ber_extention(void)
{
	ft_putstr_fd("Error :\n", 1);
	ft_putstr_fd("ERROR_MAP_NOT_BER_EXTENTION", 1);
	exit(ERROR_MAP_NOT_BER_EXTENTION);
}

void	catch_error_game_is_null(void)
{
	ft_putstr_fd("Error :\n", 1);
	ft_putstr_fd("ERROR_GAME_IS_NULL", 1);
	exit(ERROR_GAME_IS_NULL);
}

void	catch_error_map_width(void)
{
	ft_putstr_fd("Error :\n", 1);
	ft_putstr_fd("ERROR_MAP_WIDTH", 1);
	exit(ERROR_MAP_WIDTH);
}
