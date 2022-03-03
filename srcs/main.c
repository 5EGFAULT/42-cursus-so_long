/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:07:24 by asouinia          #+#    #+#             */
/*   Updated: 2021/12/14 15:18:34 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int f(t_game *game)
{
	(void)game;
	static int frames = 0;

	if (frames % 500 == 0)
	{
		// printf("%d", frames);
		if (game->coin_xpm_index_direction)

		{
			if (game->coin_xpm_index == 6)
			{
				game->coin_xpm_index--;
				game->coin_xpm_index_direction = 0;
			}
			else
			{
				game->coin_xpm_index++;
			}
		}
		else
		{
			if (game->coin_xpm_index == 0)
			{
				game->coin_xpm_index++;
				game->coin_xpm_index_direction = 1;
			}
			else
			{
				game->coin_xpm_index--;
			}
		}
		draw_map(game);
	}
	if (frames % 1000 == 0)
	{
		if (game->death_xpm_index_direction)

		{
			if (game->death_xpm_index == 5)
			{
				game->death_xpm_index--;
				game->death_xpm_index_direction = 0;
			}
			else
			{
				game->death_xpm_index++;
			}
		}
		else
		{
			if (game->death_xpm_index == 0)
			{
				game->death_xpm_index++;
				game->death_xpm_index_direction = 1;
			}
			else
			{
				game->death_xpm_index--;
			}
		}
		draw_death_block(game);
	}

	frames++;

	return 0;
}

int main(int argc, char **argv)
{
	t_game *game;
	t_mlx *mlx;
	int width;
	int height;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (1);
	game = init_game(argv[1]);
	if (!game || !game->map)
		return (1);
	width = game->width * BLOCK_SIZE;
	height = game->height * BLOCK_SIZE;
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, width, height, "asouinia so_long");
	game->mlx = mlx;
	mlx_hook(mlx->mlx_win, 2, 1L << 0, hooks, game);
	draw_map(game);
	print_map(game);
	(void)argc;
	mlx_loop_hook(mlx->mlx, f, game);

	mlx_loop(mlx);

	free(mlx->mlx_win);
	free(mlx->mlx);
	free(mlx);
	return (0);
}
