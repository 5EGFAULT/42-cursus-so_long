/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:39:13 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/04 17:14:21 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	win_game(t_game *game)
{
	int	c;

	mlx_clear_window(game->mlx->mlx, game->mlx->mlx_win);
	c = create_trgb(1, 0, 255, 0);
	mlx_string_put(game->mlx->mlx, game->mlx->mlx_win, 0, 0, c, "YOU WIN");
	game->game = 0;
}

void	lost_game(t_game *game)
{
	int	c;

	mlx_clear_window(game->mlx->mlx, game->mlx->mlx_win);
	c = create_trgb(1, 255, 0, 0);
	mlx_string_put(game->mlx->mlx, game->mlx->mlx_win, 0, 0, c, "YOU LOSE");
	game->game = 0;
}

void	close_game(void)
{
	exit(0);
}
