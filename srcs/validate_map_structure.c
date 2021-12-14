/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_structure.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 03:37:35 by asouinia          #+#    #+#             */
/*   Updated: 2021/12/14 05:34:32 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	validate_map_name(char *map_file)
{
	int	i;

	if (!map_file)
		return (0);
	i = ft_strlen(map_file);
	//? use strcmp
	if (i < 5)
		return (0);
	if (map_file[i - 4] == '.')
		if (map_file[i - 3] == 'b')
			if (map_file[i - 2] == 'e')
				if (map_file[i - 1] == 'r')
					return (1);
	return (0);
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
			while (++j < game->width)
			{
				if (game->map[i][j] != '1')
					return (0);
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
	// if (ft_strlen(game->map[i]) != game->width) //? non need width is the last element length
	// 		return (0);	
	return (1);
}