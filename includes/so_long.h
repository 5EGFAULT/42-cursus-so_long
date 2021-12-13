/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 02:46:57 by asouinia          #+#    #+#             */
/*   Updated: 2021/12/13 05:24:05 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 42
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include "../srcs/libft/libft.h"
# include "../srcs/Get_next_line/get_next_line_bonus.h"
# define PLAYER_BLOCK "test"
# define WALL_BLOCK "test"
# define COIN_BLOCK "test"
# define BG_BLOCK "test"

typedef struct s_game
{
	char	**map;
	int		count;
	int		height;
	int		width;
} t_game;
int validate_map_width(char  *map_file);
int validate_map_border(char  **map);
int validate_map_name(char  *map_file);

int validate_map_player(char  **map);
int validate_map_Exit(char  **map);
int validate_map_Coins(char  **map);
int validate_map_Other_chars(char  **map);


char    **load_map(char *map_path);



#endif