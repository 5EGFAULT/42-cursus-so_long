/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:52:03 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/04 19:51:56 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

	animate_coin(frames, game);
	if (game->game)
	{
		animate_death(frames, game);
		frames++;
	}
	return (0);
}
