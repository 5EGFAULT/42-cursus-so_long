/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:42:30 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/14 17:57:45 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

void	draw_img_block(t_game *game, char c, int x, int y)
{
	int		w;
	int		h;
	void	*img;
	char	*file;

	if (c == '0')
		file = ft_strdup(BG_BLOCK);
	if (c == 'P')
		file = ft_strdup(PLAYER_BLOCK);
	if (c == '1')
		file = ft_strdup(WALL_BLOCK);
	if (c == 'C')
		file = ft_strdup(COIN_BLOCK);
	if (c == 'E' && game->n_coins != 0)
		file = ft_strdup(EXIT_CLOSE_BLOCK);
	if (c == 'E' && game->n_coins == 0)
		file = ft_strdup(EXIT_OPEN_BLOCK);
	img = mlx_xpm_file_to_image(game->mlx, file, &w, &h);
	w = BLOCK_SIZE * x;
	h = BLOCK_SIZE * y;
	if (!img)
		catch_error_map_not_found();
	mlx_put_image_to_window(game->mlx, game->mlx_win, img, w, h);
	mlx_destroy_image(game->mlx, img);
	free(file);
}

void	draw_map(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	mlx_clear_window(game->mlx, game->mlx_win);
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
			draw_img_block(game, game->map[i][j], j, i);
	}
}

void	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
}
