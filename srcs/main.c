#include "../includes/so_long.h"


int	main(int argc, char  **argv)
{
	void	*mlx;
	void	*mlx_win;
	char	**map;

	

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
	
	(void)argc;
	(void)argv;
	return (0);
}
