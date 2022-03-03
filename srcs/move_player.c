/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:22:00 by asouinia          #+#    #+#             */
/*   Updated: 2021/12/15 10:08:13 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int can_move(t_game *game, int direction)
{
	if (direction == KEY_UP)
	{
		if (game->map[game->p_y - 1][game->p_x] == '1')
			return (0);
		if (game->map[game->p_y - 1][game->p_x] == 'E' && game->n_coins)
			return (0);
	}
	if (direction == KEY_DOWN)
	{
		if (game->map[game->p_y + 1][game->p_x] == '1')
			return (0);
		if (game->map[game->p_y + 1][game->p_x] == 'E' && game->n_coins)
			return (0);
	}
	if (direction == KEY_LEFT)
	{
		if (game->map[game->p_y][game->p_x - 1] == '1')
			return (0);
		if (game->map[game->p_y][game->p_x - 1] == 'E' && game->n_coins)
			return (0);
	}
	if (direction == KEY_RIGHT)
	{
		if (game->map[game->p_y][game->p_x + 1] == '1')
			return (0);
		if (game->map[game->p_y][game->p_x + 1] == 'E' && game->n_coins)
			return (0);
	}
	return (1);
}

void move_player(t_game *game, int direction)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (direction == KEY_UP)
		i = -1;
	if (direction == KEY_DOWN)
		i = 1;
	if (direction == KEY_LEFT)
		j = -1;
	if (direction == KEY_RIGHT)
		j = 1;
	game->map[game->p_y][game->p_x] = '0';
	game->p_y += i;
	game->p_x += j;
	if (game->map[game->p_y][game->p_x] == 'C')
		game->n_coins--;
	if (game->map[game->p_y][game->p_x] == 'E')
	{
		if (game->n_coins == 0)
		{
			mlx_destroy_window(game->mlx->mlx, game->mlx->mlx_win);
			exit(0);
		}
	}
	game->map[game->p_y][game->p_x] = 'P';
	// print_map(game);
	draw_map(game);
}

void move_death(t_game *game, int direction)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (direction == KEY_ARROW_UP)
		i = -1;
	if (direction == KEY_ARROW_DOWN)
		i = 1;
	if (direction == KEY_ARROW_LEFT)
		j = -1;
	if (direction == KEY_ARROW_RIGHT)
		j = 1;
	game->map[game->d_y][game->d_x] = '0';
	game->d_y += i;
	game->d_x += j;
	if (game->map[game->d_y][game->d_x] == 'E')
	{
		if (game->n_coins == 0)
		{
			mlx_destroy_window(game->mlx->mlx, game->mlx->mlx_win);
			exit(0);
		}
	}
	// game->map[game->p_y][game->p_x] = 'P';
	// print_map(game);
	// draw_map(game);
}

int can_move_death(t_game *game, int direction)
{
	if (direction == KEY_ARROW_UP)
	{
		if (game->map[game->d_y - 1][game->d_x] == '1' || game->map[game->d_y - 1][game->d_x] == 'C' || game->map[game->d_y][game->d_x + 1] == 'E')
			return (0);
	}
	if (direction == KEY_ARROW_DOWN)
	{
		if (game->map[game->d_y + 1][game->d_x] == '1' || game->map[game->d_y + 1][game->d_x] == 'C' || game->map[game->d_y][game->d_x + 1] == 'E')
			return (0);
	}
	if (direction == KEY_ARROW_LEFT)
	{
		if (game->map[game->d_y][game->d_x - 1] == '1' || game->map[game->d_y][game->d_x - 1] == 'C' || game->map[game->d_y][game->d_x + 1] == 'E')
			return (0);
	}
	if (direction == KEY_ARROW_RIGHT)
	{
		if (game->map[game->d_y][game->d_x + 1] == '1' || game->map[game->d_y][game->d_x + 1] == 'C' || game->map[game->d_y][game->d_x + 1] == 'E')
			return (0);
	}
	return (1);
}
