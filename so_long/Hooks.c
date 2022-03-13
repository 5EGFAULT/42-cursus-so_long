/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:42:15 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/13 20:56:49 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	movehook(t_game *game, int keycode)
{
	if (!can_move(game, keycode))
		return (0);
	move_player(game);
	return (1);
}

int	hooks(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	if ((keycode == KEY_DOWN || keycode == KEY_UP) && game->game)
		movehook(game, keycode);
	if ((keycode == KEY_LEFT || keycode == KEY_RIGHT) && game->game)
		movehook(game, keycode);
	return (0);
}

int	destroy_hook(t_game *game)
{
	close_game(game);
	return (0);
}
