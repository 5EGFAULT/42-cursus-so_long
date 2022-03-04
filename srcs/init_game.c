/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 04:21:21 by asouinia          #+#    #+#             */
/*   Updated: 2021/12/14 12:44:39 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_map(char *map_path, t_game *game)
{
	int	height;
	int	fd;
	int	i;

	height = 0;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (0);
	while (get_next_line(fd))
		height++;
	game->map = malloc(sizeof(char *) * (height));
	close(fd);
	i = -1;
	fd = open(map_path, O_RDONLY);
	while (++i < height && game->map)
		game->map[i] = get_next_line(fd);
	close(fd);
	game->height = height;
	if (game->map)
		game->width = ft_strlen(game->map[i - 1]);
	if (!game->map || !validate_map(game))
		return (free_game(&game));
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
	game->count_move = 0;
	game->c_i = 0;
	game->c_i_direction = 0;
	game->death_xpm_index = 0;
	game->death_xpm_index_direction = 0;
	if (!init_map(map_path, game))
		game = NULL;
	else
		set_init_death(game);
	return (game);
}

int	free_game(t_game **game)
{
	int	i;

	i = -1;
	while (++i < (*game)->height)
		free((*game)->map[i]);
	free((*game)->map);
	free(*game);
	*game = NULL;
	return (0);
}

void	print_map(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->height)
		printf("%s", game->map[i]);
	printf("\n\n");
}

void	set_init_death(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	game->death_exist = 0;
	while (++i < game->height - 1)
	{
		if (game->death_exist)
			break ;
		while (++j < game->width - 1)
		{
			if (game->map[i][j] == '0')
			{
				game->death_exist = 1;
				game->d_x = i;
				game->d_y = j;
				break ;
			}
		}
	}
}
