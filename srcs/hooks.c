/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:12:45 by asouinia          #+#    #+#             */
/*   Updated: 2021/12/14 12:55:58 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	movehook(t_game *game, int keycode)
{
	if (!can_move(game, keycode))
		return (0);
	move_player(game, keycode);
	return (1);
}

int	hooks(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx->mlx, game->mlx->mlx_win);
		exit(0);
	}
	if (keycode == KEY_DOWN)
		movehook(game, keycode);
	if (keycode == KEY_UP)
		movehook(game, keycode);
	if (keycode == KEY_LEFT)
		movehook(game, keycode);
	if (keycode == KEY_RIGHT)
		movehook(game, keycode);
	return (0);
}