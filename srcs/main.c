#include "../includes/so_long.h"


int	main(int argc, char  **argv)
{
	void	*mlx;
	void	*mlx_win;
	int		i = 0;
	int width;
	int height;
	t_game	*game;
	void * img;
	char *imgp = "xpm/0.xpm";
	game = init_game(argv[1]);
	if(!game || !game->map)
		return (1);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, game->width * 86, game->height * 86, "Shit");
	img = mlx_xpm_file_to_image(mlx, imgp, &width, &height);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	while (i < 6)
	{
		printf("%s",game->map[i]);
		i++;
	}
	(void)argc;
	mlx_loop(mlx);
	return (0);
}
