/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 04:21:21 by asouinia          #+#    #+#             */
/*   Updated: 2021/12/14 11:10:08 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	validate_map(t_game *game)
{
	if (!game)
		return (0);
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

int	init_map(char *map_path, t_game *game)
{
	int		height;
	int		fd;
	int		i;

	height = 0;
	fd = open(map_path, O_RDONLY);
	while (get_next_line(fd))
		height++;
	game->map = malloc(sizeof(char *) * (height));
	close(fd);
	i = -1;
	fd = open(map_path, O_RDONLY);
	while (++i < height)
		game->map[i] = get_next_line(fd);
	close(fd);
	game->height = height;
	game->width = ft_strlen(game->map[i - 1]);
	if (!validate_map(game))
	{
		free_game(&game);
		return (0);
	}
	return (1);
}

t_game	*init_game(char *map_path)
{
	t_game	*game;

	if (!validate_map_name(map_path))
		return (0);
	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	if (!init_map(map_path, game))
		game = NULL;
	return (game);
}

void	free_game(t_game	**game)
{
	int	i;

	i = -1;
	while (++i < (*game)->height)
		free((*game)->map[i]);
	free((*game)->map);
	free(*game);
	*game = NULL;
}

void	print_map(t_game	*game)
{
	int	i;

	i = -1;
	while (++i < game->height)
		printf("%s", game->map[i]);
}
