/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:22:00 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/04 14:59:23 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	can_move_old(t_game *game, int direction)
{
	if (direction == KEY_UP && game->map[game->p_y - 1][game->p_x] == '1')
		return (0);
	if (direction == KEY_UP && game->map[game->p_y - 1][game->p_x] == 'E')
		if (game->n_coins)
			return (0);
	if (direction == KEY_DOWN && game->map[game->p_y + 1][game->p_x] == '1')
		return (0);
	if (direction == KEY_DOWN && game->map[game->p_y + 1][game->p_x] == 'E')
		if (game->n_coins)
			return (0);
	if (direction == KEY_LEFT && game->map[game->p_y][game->p_x - 1] == '1')
		return (0);
	if (direction == KEY_LEFT && game->map[game->p_y][game->p_x - 1] == 'E')
		if (game->n_coins)
			return (0);
	if (direction == KEY_RIGHT && game->map[game->p_y][game->p_x + 1] == '1')
		return (0);
	if (direction == KEY_RIGHT && game->map[game->p_y][game->p_x + 1] == 'E')
		if (game->n_coins)
			return (0);
	return (1);
}

int	can_move(t_game *game, int direction)
{
	int	i;
	int	j;

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
	if (game->map[game->p_y + i][game->p_x + j] == '1')
		return (0);
	if (game->map[game->p_y + i][game->p_x + j] == 'E')
		if (game->n_coins)
			return (0);
	game->map[game->p_y][game->p_x] = '0';
	game->p_y += i;
	game->p_x += j;
	return (1);
}

void	move_player(t_game *game)
{
	if (game->map[game->p_y][game->p_x] == 'C')
		game->n_coins--;
	if (game->map[game->p_y][game->p_x] == 'E')
	{
		if (game->n_coins == 0)
			win_game(game);
	}
	game->map[game->p_y][game->p_x] = 'P';
	if (game->game)
	{
		game->count_move++;
		ft_putstr_fd("moves : ", 1);
		ft_putnbr_fd(game->count_move, 1);
		ft_putchar_fd('\n', 1);
		draw_map(game);
	}
}

void	move_death(t_game *game, int direction)
{
	int	i;
	int	j;

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
}

int	can_move_death(t_game *game, int direction)
{
	int	i;
	int	j;

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
	if (game->map[game->d_y + i][game->d_x + j] == '1')
		return (0);
	if (game->map[game->d_y + i][game->d_x + j] == 'C')
		return (0);
	if (game->map[game->d_y + i][game->d_x + j] == 'E')
		return (0);
	return (1);
}
