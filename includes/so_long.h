/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 02:46:57 by asouinia          #+#    #+#             */
/*   Updated: 2021/12/14 08:33:59 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include "../srcs/libft/libft.h"
# include "../srcs/Get_next_line/get_next_line_bonus.h"
# define PLAYER_BLOCK "xpm/p.xpm"
# define WALL_BLOCK "xpm/1.xpm"
# define COIN_BLOCK "xpm/c.xpm"
# define BG_BLOCK "xpm/0.xpm"
# define BLOCK_SIZE 51
typedef struct	s_game
{
	char	**map;
	int		count_move;
	int		height;
	int		width;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		n_coins;
} 				t_game;
int		validate_map_width(t_game *game);
int		validate_map_border(t_game *game);
int		validate_map_name(char  *map_file);

int		validate_map_player(t_game *game);
int 	validate_map_exit(t_game *game);
int 	validate_map_coins(t_game *game);
int		validate_map_other_chars(t_game *game);


int	validate_map(t_game *game);
int		init_map(char *map_path, t_game *game);
t_game	*init_game(char *map_path);
void	free_game(t_game	**game);
void	print_map(t_game	*game);


void	draw_map(t_game *game, void *mlx, void	*mlx_win);

#endif