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
	move_player(game);
	return (1);
}

int	move_death_hook(t_game *game, int keycode)
{
	if (!can_move_death(game, keycode))
		return (0);
	move_death(game, keycode);
	return (1);
}

int	hooks(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	if (keycode == KEY_DOWN || keycode == KEY_UP)
		movehook(game, keycode);
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		movehook(game, keycode);
	if (game->death_exist)
	{
		if (keycode == KEY_ARROW_DOWN || keycode == KEY_ARROW_UP)
			move_death_hook(game, keycode);
		if (keycode == KEY_ARROW_LEFT || keycode == KEY_ARROW_RIGHT)
			move_death_hook(game, keycode);
		if (game->d_x == game->p_x && game->d_y == game->p_y)
			exit(1);
	}
	return (0);
}
