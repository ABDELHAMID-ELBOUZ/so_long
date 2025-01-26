// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/01/21 09:56:02 by aelbouz           #+#    #+#             */
// /*   Updated: 2025/01/26 09:57:03 by aelbouz          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "so_long.h"

// void	free_map(char **map, int j)
// {
// 	while (map[j])
// 	{
// 		free(map[j++]);
// 	}
// 	free (map);
// }

// void	f(void)
// {
// 	system("leaks so_long");
// }

// int	main(int ac, char **av)
// {
// 	t_data	data;
// 	t_game	game;
// 	int		cols;
// 	int		rows;

// 	ft_printf("\n%d\n", lines_count(av[1]));
// 	atexit(f);
// 	if (ac != 2)
// 		return (ft_printf("Error\nuse ./so_long [map].ber\n"), exit (0), 0);
// 	if (!map_valid(av))
// 		return (free_map(av, 0), exit(0), 0);
// 	map_size(av[1],&rows, &cols);
// 	ft_printf("\n%d\n%d\n", rows, cols);
// 	creat_window(&data);
// 	mlx_loop(data.mlx);
// 	img_to_window(&game, av[1]);
// }
// int load_image(t_game *game, char *path, void **img, int *w, int *h)
// {
//    *img = mlx_xpm_file_to_image(game->mlx, path, w, h);
   
//    if (*img == NULL) {
//        ft_printf("Error: Failed to load image %s\n", path);
//        return (0);
//    }
   
//    return (1);
// }
// void render_map(t_game *game, t_data *data)
// {
//     // Assuming you have a map loaded into game->map
//     int x = 0;
//     while (x < game->map_height)
//     {
//         int y = 0;
//         while (y < game->map_width)
//         {
//             if (game->map[x][y] == '1')
//                 mlx_put_image_to_window(data->mlx, data->win, game->w_img, y * 64, x * 64);
//             if (game->map[x][y] == 'E')
//                 mlx_put_image_to_window(data->mlx, data->win, game->e_img, y * 64, x * 64);
//             if (game->map[x][y] == 'P')
//                 mlx_put_image_to_window(data->mlx, data->win, game->p_img, y * 64, x * 64);
//             if (game->map[x][y] == 'C')
//                 mlx_put_image_to_window(data->mlx, data->win, game->c_img, y * 64, x * 64);
//             y++;
//         }
//         x++;
//     }
// }
// // Usage example:
// int main(int ac, char **av)
// {
//     t_game game;
//     t_data data;
//     int width, height;
// 	*av = NULL;
//     // Check arguments
//     if (ac != 2)
//         return (ft_printf("Error\nUsage: ./so_long [map].ber\n"), 0);

//     // Initialize MLX
//     data.mlx = mlx_init();
    
//     // Load images
//     load_image(&game, "pac_up3.xpm", &game.w_img, &width, &height);
//     load_image(&game, "pac_up3.xpm", &game.e_img, &width, &height);
//     load_image(&game, "pac_up3.xpm", &game.p_img, &width, &height);
//     load_image(&game, "pac_up3.xpm", &game.c_img, &width, &height);

//     // Create window
//     data.win = mlx_new_window(data.mlx, 640, 480, "So Long");

//     // Render map or images
//     render_map(&game, &data);

//     // Start MLX loop
//     mlx_loop(data.mlx);

//     return (0);
// }