/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Loops_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:01:43 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/14 21:26:52 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

void	animate_coin(int frames, t_game *game)
{
	if (frames % 500 == 0)
	{
		if (game->c_i_direction)
		{
			if (game->c_i == 6)
			{
				game->c_i--;
				game->c_i_direction = 0;
			}
			else
				game->c_i++;
		}
		else
		{
			if (game->c_i == 0)
			{
				game->c_i++;
				game->c_i_direction = 1;
			}
			else
				game->c_i--;
		}
		draw_map(game);
		draw_death_block(game);
	}
}

void	animate_death(int frames, t_game *game)
{
	if (game->death_exist && frames % 1000 == 0)
	{
		if (game->death_xpm_index_direction)
		{
			if (game->death_xpm_index == 5)
			{
				game->death_xpm_index--;
				game->death_xpm_index_direction = 0;
			}
			else
				game->death_xpm_index++;
		}
		else
		{
			if (game->death_xpm_index == 0)
			{
				game->death_xpm_index++;
				game->death_xpm_index_direction = 1;
			}
			else
				game->death_xpm_index--;
		}
		draw_death_block(game);
	}
}

int	loops(t_game *game)
{
	static int	frames = 0;
	static int	rand = 1;

	animate_coin(frames, game);
	if (game->game)
	{
		animate_death(frames, game);
		if (game->death_exist && game->game && frames % 1000 == 0)
		{
			if (rand % 5 == 0)
				move_death_hook(game, KEY_ARROW_UP);
			if (rand % 5 == 1)
				move_death_hook(game, KEY_ARROW_DOWN);
			if (rand % 5 == 2)
				move_death_hook(game, KEY_ARROW_LEFT);
			if (rand % 5 == 3)
				move_death_hook(game, KEY_ARROW_RIGHT);
			if (game->d_x == game->p_x && game->d_y == game->p_y)
				close_game(game);
		}
		frames++;
		rand *= 13;
	}
	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
