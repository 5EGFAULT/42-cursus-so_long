/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:39:18 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/04 14:23:43 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	hundle_error(t_game *game, int error)
{
	free_game(&game);
	if (error == ERROR_MAP_NOT_FOUND)
		catch_error_map_not_found();
	if (error == ERROR_MAP_NOT_VALID)
		catch_error_map_not_valid();
	if (error == ERROR_MAP_NOT_BER_EXTENTION)
		catch_error_map_not_ber_extention();
	if (error == ERROR_GAME_IS_NULL)
		catch_error_game_is_null();
	if (error == ERROR_MAP_WIDTH)
		catch_error_map_width();
	if (error == ERROR_MAP_BORDER)
		catch_error_map_border();
	if (error == ERROR_MAP_PLAYER)
		catch_error_map_player();
	if (error == ERROR_MAP_EXIT)
		catch_error_map_exit();
	if (error == ERROR_MAP_FOUND_FORBIDDEN_OBJECT)
		catch_error_map_found_forbidden_object();
	hundle_error_1(error);
}

void	hundle_error_1(int error)
{
	if (error == ERROR_MAP_WIDTH)
		catch_error_map_not_found();
}
