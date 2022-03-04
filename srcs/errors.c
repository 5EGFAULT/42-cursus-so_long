/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:39:18 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/04 12:28:24 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	hundle_error(t_game *game, int error)
{
	ft_putstr_fd("Error :\n", 1);
	if (error == ERROR_MAP_NOT_FOUND)
		ERROR_MAP_NOT_FOUND();
	if (error == ERROR_MAP_NOT_VALID)
		ERROR_MAP_NOT_VALID();
	if (error == ERROR_MAP_NOT_BER_EXTENTION)
		ERROR_MAP_NOT_BER_EXTENTION();
	if (error == ERROR_GAME_IS_NULL)
		ERROR_GAME_IS_NULL();
	if (error == ERROR_MAP_WIDTH)
		ERROR_MAP_WIDTH();
	if (error == ERROR_MAP_BORDER)
		ERROR_MAP_BORDER();
	if (error == ERROR_MAP_PLAYER)
		ERROR_MAP_PLAYER();
	if (error == ERROR_MAP_EXIT)
		ERROR_MAP_EXIT();
	if (error == ERROR_MAP_FOUND_FORBIDDEN_OBJECT)
		ERROR_MAP_FOUND_FORBIDDEN_OBJECT();
	hundle_error_1(game, error);
}

void	hundle_error_1(t_game *game, int error)
{
	if (error == ERROR_MAP_WIDTH)
		ERROR_MAP_NOT_FOUND();
}
