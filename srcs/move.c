/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:00:18 by jrobert           #+#    #+#             */
/*   Updated: 2022/01/12 17:35:59 by jrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_game *game)
{
	if (game->map[game->pos_y - 1][game->pos_x] == 'E'
		&& game->coins == game->c)
		win(game);
	else if (game->map[game->pos_y - 1][game->pos_x] != '1')
	{
		game->moves++;
		if (game->map[game->pos_y - 1][game->pos_x] == 'C')
			game->coins++;
		update_panel(game);
		reset_texture(game);
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win_ptr,
			game->mario.ptr, game->pos_x * 35, (game->pos_y - 1) * 35);
		game->pos_y--;
	}
	return (0);
}

int	move_down(t_game *game)
{
	if (game->map[game->pos_y + 1][game->pos_x] == 'E'
		&& game->coins == game->c)
		win(game);
	else if (game->map[game->pos_y + 1][game->pos_x] != '1')
	{
		game->moves++;
		if (game->map[game->pos_y + 1][game->pos_x] == 'C')
			game->coins++;
		update_panel(game);
		reset_texture(game);
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win_ptr,
			game->mario.ptr, game->pos_x * 35, (game->pos_y + 1) * 35);
		game->pos_y++;
	}
	return (0);
}

int	move_left(t_game *game)
{
	if (game->map[game->pos_y][game->pos_x - 1] == 'E'
		&& game->coins == game->c)
		win(game);
	else if (game->map[game->pos_y][game->pos_x - 1] != '1')
	{
		game->moves++;
		if (game->map[game->pos_y][game->pos_x - 1] == 'C')
			game->coins++;
		update_panel(game);
		reset_texture(game);
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win_ptr,
			game->mario.ptr, (game->pos_x - 1) * 35, game->pos_y * 35);
		game->pos_x--;
	}
	return (0);
}

int	move_right(t_game *game)
{
	if (game->map[game->pos_y][game->pos_x + 1] == 'E'
		&& game->coins == game->c)
		win(game);
	else if (game->map[game->pos_y][game->pos_x + 1] != '1')
	{
		game->moves++;
		if (game->map[game->pos_y][game->pos_x + 1] == 'C')
			game->coins++;
		update_panel(game);
		reset_texture(game);
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win_ptr,
			game->mario.ptr, (game->pos_x + 1) * 35, game->pos_y * 35);
		game->pos_x++;
	}
	return (0);
}
