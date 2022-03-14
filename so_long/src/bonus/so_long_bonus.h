/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:28:35 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/14 17:57:29 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include "./get_next_line_bonus.h"
# include "../libft/libft.h"
# define BLOCK_SIZE 50
# define BUFFER_SIZE 1
//! 	 XPM PATHS
# define PLAYER_BLOCK "xpm/p.xpm"
# define WALL_BLOCK "xpm/1.xpm"
# define COIN_BLOCK "xpm/c-4.xpm"
# define BG_BLOCK "xpm/0.xpm"
# define EXIT_OPEN_BLOCK "xpm/e_o.xpm"
# define EXIT_CLOSE_BLOCK "xpm/e_c.xpm"
//! 	 EVENT KEYS CODES
# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_ESC 53
//!		 ERRORS
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

typedef struct s_game
{
	char	**map;
	int		game;
	int		count_move;
	int		height;
	int		width;
	int		p_x;
	int		p_y;
	int		n_coins;
	void	*mlx;
	void	*mlx_win;
}				t_game;

//!		ValidateMapStructure.c
int		validate_map(t_game *game);
int		validate_map_width(t_game *game);
int		validate_map_border(t_game *game);
int		validate_map_name(char *map_file);
//!		ValidateMapObjects.c
int		validate_map_player(t_game *game);
int		validate_map_exit(t_game *game);
int		validate_map_coins(t_game *game);
int		validate_map_other_chars(t_game *game);
//!		Errors2.c
void	catch_error_map_border(void);
void	catch_error_map_player(void);
void	catch_error_map_exit(void);
void	catch_error_map_found_forbidden_object(void);
//!		Errors1.c
void	catch_error_map_not_found(void);
void	catch_error_map_not_valid(void);
void	catch_error_map_not_ber_extention(void);
void	catch_error_game_is_null(void);
void	catch_error_map_width(void);
//!		Hooks.c
int		movehook(t_game *game, int keycode);
int		hooks(int keycode, t_game *game);
int		destroy_hook(t_game *game);
//!		Init.c
int		init_map(char *map_path, t_game *game);
t_game	*init_game(char *map_path);
int		free_game(t_game **game);
int		count_height(int fd);
//!		Movement.c
int		can_move(t_game *game, int direction);
void	move_player(t_game *game);
//!		Render.c
void	draw_img_block(t_game *game, char c, int x, int y);
void	draw_map(t_game *game);
void	close_game(t_game *game);

#endif