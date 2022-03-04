/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_structure.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 03:37:35 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/04 13:30:48 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	validate_map_name(char *map_file)
{
	char	*s;

	if (!map_file)
		return (0);
	s = ft_strrchr(map_file, '.');
	if (ft_strlen(map_file) < 5)
		return (0);
	if (ft_strncmp(s, ".ber", 4))
		return (0);
	return (1);
}

int	validate_map_border(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		if (i == 0 || i == game->height -1)
		{
			while (++j < game->width)
			{
				if (game->map[i][j] != '1')
					return (0);
			}
		}
		if (game->map[i][0] != '1')
			return (0);
		if (game->map[i][game->width - 1] != '1')
			return (0);
	}
	return (1);
}

int	validate_map_width(t_game *game)
{
	int	i;

	i = -1;
	if (!game || !game->map)
		return (0);
	while (++i < game->height - 1)
	{	
		if (ft_strlen(game->map[i]) - 1 != (size_t)game->width)
			return (0);
	}
	return (1);
}

int	validate_map(t_game *game)
{
	if (!game)
		catch_error_game_is_null(0);
	if (!validate_map_width(game))
		return (0);
	if (!validate_map_border(game))
		return (0);
	if (!validate_map_player(game))
		return (0);
	if (!validate_map_exit(game))
		return (0);
	if (!validate_map_coins(game))
		return (0);
	if (!validate_map_other_chars(game))
		return (0);
	return (1);
}
