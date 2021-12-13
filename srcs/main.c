#include "../includes/so_long.h"


int	main(int argc, char  **argv)
{
	// void	*mlx;
	// void	*mlx_win;
	char	**map;
	int		i = 0;	

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// mlx_loop(mlx);
	map = load_map(argv[1]);
	while (i < 6)
	{
		printf("%s",map[i]);
		i++;
	}
	(void)argc;
	(void)argv;
	return (0);
}
