/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:01:21 by jrobert           #+#    #+#             */
/*   Updated: 2022/01/12 17:37:43 by jrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_game *game)
{
	game->mlx.w = game->cols * 35;
	game->mlx.h = game->rows * 35;
	game->mlx.ptr = mlx_init();
	if (!game->mlx.ptr)
		exit_game(game, "MLX init failed");
	game->mlx.win_ptr = mlx_new_window(game->mlx.ptr, game->mlx.w,
			game->mlx.h, "so_long");
	if (!game->mlx.win_ptr)
		exit_game(game, "Window init failed");
}

int	main(int argc, char **argv)
{
	t_game	game;

	game = (t_game){};
	if (argc != 2)
		exit_game(&game, "Please provide 1 map");
	if (!ft_strchr(argv[1], '.') || ft_strncmp(ft_strchr(argv[1], '.'),
			".ber", 4))
		exit_game(&game, "Invalid file type [.ber]");
	check_shape(argv[1], &game);
	if (parse_map(argv[1], &game))
		exit_game(&game, "Error in map parsing");
	check_border(&game);
	check_content(&game);
	init_mlx(&game);
	create_textures(&game);
	draw_content(&game);
	draw_score(&game);
	mlx_key_hook(game.mlx.win_ptr, deal_key, &game);
	mlx_hook(game.mlx.win_ptr, 17, 0, close_win, &game);
	ft_putstr_fd("Moves : 0\n", 1);
	mlx_loop(game.mlx.ptr);
}
