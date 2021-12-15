/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 07:48:49 by asouinia          #+#    #+#             */
/*   Updated: 2021/12/15 10:07:49 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_img_block(t_game *game, char c, int x, int y)
{
	int		w;
	int		h;
	void	*img;
	char	*file;

	file = NULL;
	if (c == '0')
		file = BG_BLOCK;
	if (c == 'P')
		file = PLAYER_BLOCK;
	if (c == '1')
		file = WALL_BLOCK;
	if (c == 'C')
		file = COIN_BLOCK;
	if (c == 'E' && game->n_coins != 0)
		file = EXIT_CLOSE_BLOCK;
	if (c == 'E' && game->n_coins == 0)
		file = EXIT_OPEN_BLOCK;
	img = mlx_xpm_file_to_image(game->mlx->mlx, file, &w, &h);
	w = BLOCK_SIZE * x;
	h = BLOCK_SIZE * y;
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->mlx_win, img, w, h);
	mlx_destroy_image(game->mlx->mlx, img);
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	mlx_clear_window(game->mlx->mlx, game->mlx->mlx_win);
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
			draw_img_block(game, game->map[i][j], j, i);
	}
}
