/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:39:13 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/04 14:55:59 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	win_game(t_game *game)
{
	mlx_clear_window(game->mlx->mlx, game->mlx->mlx_win);
	game->game = 0;
}

void	lost_game(t_game *game)
{
	mlx_clear_window(game->mlx->mlx, game->mlx->mlx_win);
	game->game = 0;
}

void	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx->mlx, game->mlx->mlx_win);
	free_game(&game);
	exit(0);
}
