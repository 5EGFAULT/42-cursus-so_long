/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:07:24 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/04 19:49:18 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	t_mlx	*mlx;
	int		width;
	int		height;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx || argc <= 1)
		return (1);
	game = init_game(argv[1]);
	if (!game || !game->map)
		catch_error_game_is_null();
	width = game->width * BLOCK_SIZE;
	height = game->height * BLOCK_SIZE;
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, width, height, "asouinia so_long");
	game->mlx = mlx;
	mlx_hook(mlx->mlx_win, 2, 1L << 0, hooks, game);
	mlx_hook(mlx->mlx_win, 17, 1L << 0, destroy_hook, game);
	mlx_loop_hook(mlx->mlx, loops, game);
	mlx_loop(mlx);
	free(mlx->mlx_win);
	free(mlx->mlx);
	free(mlx);
	return (0);
}
