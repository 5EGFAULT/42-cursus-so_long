#include "../includes/so_long.h"


int	main(int argc, char  **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_game	*game;

	game = init_game(argv[1]);
	if(!game || !game->map)
		return (1);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, game->width * BLOCK_SIZE, game->height * BLOCK_SIZE, "Shit");
	draw_map(game, mlx_win, mlx_win);
	print_map(game);
	(void)argc;
	mlx_loop(mlx);
	return (0);
}
