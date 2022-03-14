/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:42:30 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/14 21:26:44 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

static char	*get_file(char *start, int idx)
{
	char	*file;
	char	*tmp1;
	char	*tmp2;

	tmp1 = ft_itoa(idx);
	tmp2 = ft_strjoin(start, tmp1);
	file = ft_strjoin(tmp2, ".xpm");
	free(tmp1);
	free(tmp2);
	return (file);
}

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
		file = get_file(COIN_BLOCK, game->c_i);
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
	char	*str;
	int		c;

	i = -1;
	mlx_clear_window(game->mlx, game->mlx_win);
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
			draw_img_block(game, game->map[i][j], j, i);
	}
	str = ft_itoa(game->count_move);
	c = create_trgb(1, 0, 255, 0);
	mlx_string_put(game->mlx, game->mlx_win, 0, 0, c, "moves : ");
	mlx_string_put(game->mlx, game->mlx_win, 100, 0, c, str);
	free(str);
}

void	draw_death_block(t_game *game)
{
	int		w;
	int		h;
	void	*img;
	char	*file;

	if (game->death_exist)
	{
		file = get_file(DEATH_BLOCK, game->death_xpm_index);
		img = mlx_xpm_file_to_image(game->mlx, file, &w, &h);
		if (!img)
			catch_error_map_not_found();
		w = BLOCK_SIZE * game->d_x;
		h = BLOCK_SIZE * game->d_y;
		mlx_put_image_to_window(game->mlx, game->mlx_win, img, w, h);
		mlx_destroy_image(game->mlx, img);
		free(file);
	}
}

void	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
}
