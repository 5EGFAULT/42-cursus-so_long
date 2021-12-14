/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:07:24 by asouinia          #+#    #+#             */
/*   Updated: 2021/12/14 12:12:59 by asouinia         ###   ########.fr       */
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
	if (!mlx)
		return (1);
	game = init_game(argv[1]);
	if (!game || !game->map)
		return (1);
	width = game->width * BLOCK_SIZE;
	height = game->height * BLOCK_SIZE;
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, width, height, "Shit");
	game->mlx = mlx;
	mlx_hook(mlx->mlx_win, 2, 1L << 0, hooks, game);
	draw_map(game, mlx);
	print_map(game);
	(void)argc;
	mlx_loop(mlx);
	free(mlx->mlx_win);
	free(mlx->mlx);
	free(mlx);
	return (0);
}
