/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 02:46:57 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/04 15:39:24 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include "../srcs/libft/libft.h"
# include "../srcs/Get_next_line/get_next_line_bonus.h"
# define BLOCK_SIZE 50
# define BUFFER_SIZE 1
//? XPM PATHS
# define PLAYER_BLOCK "xpm/p.xpm"
# define WALL_BLOCK "xpm/1.xpm"
# define COIN_BLOCK "xpm/c-"
# define DEATH_BLOCK "xpm/d-"
# define BG_BLOCK "xpm/0.xpm"
# define EXIT_OPEN_BLOCK "xpm/e_o.xpm"
# define EXIT_CLOSE_BLOCK "xpm/e_c.xpm"
//? EVENT KEYS CODES
# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_ESC 53

# define KEY_ARROW_UP 126
# define KEY_ARROW_DOWN 125
# define KEY_ARROW_LEFT 123
# define KEY_ARROW_RIGHT 124
//? ERRORS
# define ERROR_MAP_NOT_FOUND 1 
# define ERROR_MAP_NOT_VALID 2 
# define ERROR_MAP_WIDTH 3
# define ERROR_MAP_BORDER 4
# define ERROR_MAP_PLAYER 5
# define ERROR_MAP_EXIT 6
# define ERROR_MAP_COINS 7
# define ERROR_MAP_FOUND_FORBIDDEN_OBJECT 8
# define ERROR_MAP_NOT_BER_EXTENTION 9
# define ERROR_GAME_IS_NULL 100

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

typedef struct s_game
{
	char	**map;
	int		game;
	int		c_i;
	int		c_i_direction;
	int		death_xpm_index;
	int		death_xpm_index_direction;
	int		death_exist;
	int		d_x;
	int		d_y;
	int		count_move;
	int		height;
	int		width;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		n_coins;
	t_mlx	*mlx;
}				t_game;

//? validate_map_structure.c
int		validate_map(t_game *game);
int		validate_map_width(t_game *game);
int		validate_map_border(t_game *game);
int		validate_map_name(char *map_file);
//? validate_map_objects.c
int		validate_map_player(t_game *game);
int		validate_map_exit(t_game *game);
int		validate_map_coins(t_game *game);
int		validate_map_other_chars(t_game *game);
//? init_game.c
t_game	*init_game(char *map_path);
int		free_game(t_game **game);
void	print_map(t_game *game);
void	set_init_death(t_game *game);
//? draw.c
int		create_trgb(int t, int r, int g, int b);
void	draw_map(t_game *game);
void	draw_death_block(t_game *game);
//? hooks.c
int		hooks(int keycode, t_game *game);
int		movehook(t_game *game, int keycode);
//? move.c
int		can_move(t_game *game, int direction);
void	move_player(t_game *game);
void	move_death(t_game *game, int direction);
int		can_move_death(t_game *game, int direction);
//? loops.c
int		loops(t_game *game);
//? endgame.c
void	win_game(t_game *game);
void	lost_game(t_game *game);
void	close_game(t_game *game);
//? errors2.c
void	catch_error_map_border(void);
void	catch_error_map_player(void);
void	catch_error_map_exit(void);
void	catch_error_map_found_forbidden_object(void);
//? errors1.c
void	catch_error_map_not_found(void);
void	catch_error_map_not_valid(void);
void	catch_error_map_not_ber_extention(void);
void	catch_error_game_is_null(void);
void	catch_error_map_width(void);
#endif