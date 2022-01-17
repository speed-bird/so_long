/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:58:08 by jrobert           #+#    #+#             */
/*   Updated: 2022/01/12 17:05:01 by jrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_textures(t_game *game)
{
	if (game->mario.ptr)
		mlx_destroy_image(game->mlx.ptr, game->mario.ptr);
	if (game->bg.ptr)
		mlx_destroy_image(game->mlx.ptr, game->bg.ptr);
	if (game->wall.ptr)
		mlx_destroy_image(game->mlx.ptr, game->wall.ptr);
	if (game->coin.ptr)
		mlx_destroy_image(game->mlx.ptr, game->coin.ptr);
	if (game->exit.ptr)
		mlx_destroy_image(game->mlx.ptr, game->exit.ptr);
	if (game->success.ptr)
		mlx_destroy_image(game->mlx.ptr, game->success.ptr);
}

int	exit_game(t_game *game, char *error_txt)
{
	int	y;

	y = 0;
	if (game->map)
	{
		while (y < game->rows && game->map[y])
			free(game->map[y++]);
		free(game->map);
	}
	destroy_textures(game);
	if (game->mlx.win_ptr)
		mlx_destroy_window(game->mlx.ptr, game->mlx.win_ptr);
	if (game->mlx.ptr)
		free(game->mlx.ptr);
	if (error_txt)
		ft_putstr_fd(ft_strjoin(ft_strjoin("Error\n# ", error_txt), " #\n"), 1);
	else
		ft_putstr_fd("-= Game ended =-\n", 1);
	exit(0);
}

int	close_win(t_game *game)
{
	exit_game(game, NULL);
	return (0);
}
