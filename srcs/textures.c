/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:21:03 by jrobert           #+#    #+#             */
/*   Updated: 2022/01/12 17:29:04 by jrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_textures_a(t_game *game)
{
	game->wall.ptr = mlx_xpm_file_to_image(game->mlx.ptr,
			"./textures/wall 35px.xpm", &game->wall.w, &game->wall.h);
	if (!game->wall.ptr)
		exit_game(game, "Error creating texture : wall");
	game->wall.px = mlx_get_data_addr(game->wall.ptr, &game->wall.bpp,
			&game->wall.ll, &game->wall.end);
	game->coin.ptr = mlx_xpm_file_to_image(game->mlx.ptr,
			"./textures/coin 35px.xpm", &game->coin.w, &game->coin.h);
	if (!game->coin.ptr)
		exit_game(game, "Error creating texture : coin");
	game->coin.px = mlx_get_data_addr(game->coin.ptr, &game->coin.bpp,
			&game->coin.ll, &game->coin.end);
	game->exit.ptr = mlx_xpm_file_to_image(game->mlx.ptr,
			"./textures/exit 35px.xpm", &game->exit.w, &game->exit.h);
	if (!game->exit.ptr)
		exit_game(game, "Error creating texture : exit");
	game->exit.px = mlx_get_data_addr(game->exit.ptr, &game->exit.bpp,
			&game->exit.ll, &game->exit.end);
	game->mario.ptr = mlx_xpm_file_to_image(game->mlx.ptr,
			"./textures/mario 35px.xpm", &game->mario.w, &game->mario.h);
	if (!game->mario.ptr)
		exit_game(game, "Error creating texture : mario");
	game->mario.px = mlx_get_data_addr(game->mario.ptr, &game->mario.bpp,
			&game->mario.ll, &game->mario.end);
}

void	create_textures_b(t_game *game)
{
	game->bg.w = 35;
	game->bg.h = 35;
	game->bg.ptr = mlx_new_image(game->mlx.ptr, game->bg.w, game->bg.h);
	if (!game->bg.ptr)
		exit_game(game, "Error creating texture : bg");
	game->bg.px = mlx_get_data_addr(game->bg.ptr, &game->bg.bpp,
			&game->bg.ll, &game->bg.end);
	my_mlx_pixel_put(&game->bg, 0, 0, rgb_to_int(135, 206, 235));
	game->success.ptr = mlx_xpm_file_to_image(game->mlx.ptr,
			"./textures/win 82.xpm", &game->success.w, &game->success.h);
	if (!game->success.ptr)
		exit_game(game, "Error creating texture : success");
	game->success.px = mlx_get_data_addr(game->success.ptr, &game->success.bpp,
			&game->success.ll, &game->success.end);
}

void	create_textures(t_game *game)
{
	create_textures_a(game);
	create_textures_b(game);
}
