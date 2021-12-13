/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 04:21:21 by asouinia          #+#    #+#             */
/*   Updated: 2021/12/13 06:08:05 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// int	validate_map(char *map_path)
// {
// 	int		height;
// 	int		width;
// 	char	*line;
// 	int		fd;
// 	char	*tmp;

// 	if (!validate_map_name(map_path))
// 		return (0);
// 	return (height);
// }

char	**init_map(char	**map, int height, char *map_path)
{
	int		fd;
	int		i;

	i = -1;
	fd = open(map_path,O_RDONLY);
	while (++i < height)
	{
		map[i] = get_next_line(fd);
	}
	close(fd);
	return (map);
}

char    **load_map(char *map_path)
{
	int		height;
	char	**map;
	int		fd;
	
	height = 0;
	map = NULL;
	fd = open(map_path,O_RDONLY);
	while (ft_strlen(get_next_line(fd)) > 0)
	{
		height++;
	}
	if (height > 2)
		map = malloc(sizeof(char *) * (height));
	close(fd);
	printf("%d",height);
	init_map(map, height, map_path);
	return (map);
}
