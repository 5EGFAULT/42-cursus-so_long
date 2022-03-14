/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:42:27 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/14 17:57:49 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

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
			close_game(game);
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
