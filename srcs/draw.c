/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 07:48:49 by asouinia          #+#    #+#             */
/*   Updated: 2021/12/14 08:45:56 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*get_img_block(void *mlx, char c)
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
	if (c == 'E')
		file = WALL_BLOCK;
	img = mlx_xpm_file_to_image(mlx, file, &w, &h);
	return (img);
}

void	draw_map(t_game *game, void *mlx, void	*mlx_win)
{
	int	i;
	int	j;
	void	*img;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			img = get_img_block(mlx, game->map[i][j]);
			mlx_put_image_to_window(mlx, mlx_win, img, BLOCK_SIZE * j, BLOCK_SIZE * i);
		}
	}
}

