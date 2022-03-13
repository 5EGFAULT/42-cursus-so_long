/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ValidateMapObjects.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:42:35 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/13 21:41:01 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	validate_map_player(t_game *game)
{
	int	n_player;
	int	i;
	int	j;

	n_player = 0;
	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == 'P')
			{
				n_player++;
				game->p_x = j;
				game->p_y = i;
			}
		}		
	}
	if (n_player == 1)
		return (1);
	else
		return (0);
}

int	validate_map_exit(t_game *game)
{
	int	n_exits;
	int	i;
	int	j;

	n_exits = 0;
	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == 'E')
				n_exits++;
		}		
	}
	if (n_exits >= 1)
		return (1);
	else
		return (0);
}

int	validate_map_coins(t_game *game)
{
	int	n_coins;
	int	i;
	int	j;

	n_coins = 0;
	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == 'C')
				n_coins++;
		}		
	}
	game->n_coins = n_coins;
	if (n_coins > 0)
		return (1);
	else
		return (0);
}

int	validate_map_other_chars(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (!ft_strchr("EPC01", game->map[i][j]))
				return (0);
		}		
	}
	return (1);
}
