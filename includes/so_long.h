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

#ifndef	SO_LONG_H
#define	SO_LONG_H
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include "../srcs/libft/libft.h"
# include "../srcs/Get_next_line/get_next_line_bonus.h"
# define BLOCK_SIZE 50
# define BUFFER_SIZE 1
//? XPM PATHS
#define PLAYER_BLOCK "xpm/p.xpm"
#define WALL_BLOCK "xpm/1.xpm"
#define COIN_BLOCK "xpm/c-"
#define DEATH_BLOCK "xpm/d-"
#define BG_BLOCK "xpm/0.xpm"
#define EXIT_OPEN_BLOCK "xpm/e_o.xpm"
#define EXIT_CLOSE_BLOCK "xpm/e_c.xpm"
//? EVENT KEYS CODES
# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_ESC 53

#define KEY_ARROW_UP 126
#define KEY_ARROW_DOWN 125
#define KEY_ARROW_LEFT 123
#define KEY_ARROW_RIGHT 124
//? ERRORS
typedef struct s_mlx
{
	void *mlx;
	void *mlx_win;
} t_mlx;
typedef struct s_game
{
	char **map;
	int c_i;
	int c_i_direction;
	int death_xpm_index;
	int death_xpm_index_direction;
	int death_exist;
	int d_x;
	int d_y;
	int count_move;
	int height;
	int width;
	int p_x;
	int p_y;
	int e_x;
	int e_y;
	int n_coins;
	t_mlx *mlx;
} t_game;
int		validate_map_width(t_game *game);
int		validate_map_border(t_game *game);
int		validate_map_name(char *map_file);
int		validate_map_player(t_game *game);
int		validate_map_exit(t_game *game);
int		validate_map_coins(t_game *game);
int		validate_map_other_chars(t_game *game);
int		validate_map(t_game *game);
int 	nit_map(char *map_path, t_game *game);
t_game *init_game(char *map_path);
int		free_game(t_game **game);
void	print_map(t_game *game);
void	set_init_death(t_game *game);
void	draw_map(t_game *game);
void	draw_death_block(t_game *game);
int		hooks(int keycode, t_game *game);
int		movehook(t_game *game, int keycode);
//? move.c
int		can_move(t_game *game, int direction);
void	move_player(t_game *game);
void	move_death(t_game *game, int direction);
int		can_move_death(t_game *game, int direction);
//? loops.c
int		loops(t_game *game);

#endif