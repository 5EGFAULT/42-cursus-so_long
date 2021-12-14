/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 02:46:57 by asouinia          #+#    #+#             */
/*   Updated: 2021/12/14 15:18:08 by asouinia         ###   ########.fr       */
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
# define EXIT_OPEN_BLOCK "xpm/e_o.xpm"
# define EXIT_CLOSE_BLOCK "xpm/e_c.xpm"
# define BLOCK_SIZE 50
# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_ESC 53

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}t_mlx;

typedef struct s_game
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
	t_mlx	*mlx;
}t_game;

int		validate_map_width(t_game *game);
int		validate_map_border(t_game *game);
int		validate_map_name(char *map_file);

int		validate_map_player(t_game *game);
int		validate_map_exit(t_game *game);
int		validate_map_coins(t_game *game);
int		validate_map_other_chars(t_game *game);

int		validate_map(t_game *game);
int		init_map(char *map_path, t_game *game);
t_game	*init_game(char *map_path);
void	free_game(t_game	**game);
void	print_map(t_game	*game);

void	draw_map(t_game *game);

int		hooks(int keycode, t_game *game);
int		movehook(t_game *game, int keycode);

int		can_move(t_game *game, int direction);
void	move_player(t_game *game, int direction);

#endif