/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:42:24 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/14 21:08:48 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	int		width;
	int		height;

	if (argc <= 1)
		catch_error_map_not_found();
	game = init_game(argv[1]);
	if (!game || !game->map)
		catch_error_game_is_null();
	width = game->width * BLOCK_SIZE;
	height = game->height * BLOCK_SIZE;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, width, height, "so_long");
	draw_map(game);
	mlx_hook(game->mlx_win, 2, 1L << 0, hooks, game);
	mlx_hook(game->mlx_win, 17, 1L << 0, destroy_hook, game);
	mlx_loop_hook(game->mlx, loops, game);
	mlx_loop(game->mlx);
	free(game->mlx_win);
	free(game->mlx);
	free(game);
	return (0);
}
