/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:59:25 by jrobert           #+#    #+#             */
/*   Updated: 2022/01/12 17:33:13 by jrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_panel(t_game *game)
{
	write(1, "Moves : ", 8);
	ft_putnbr_fd(game->moves, 1);
	write(1, "\n", 1);
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win_ptr,
		game->wall.ptr, 70, 0);
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win_ptr,
		game->wall.ptr, 105, 0);
	mlx_string_put(game->mlx.ptr, game->mlx.win_ptr, 70, 16, WHI,
		ft_itoa(game->moves));
	mlx_string_put(game->mlx.ptr, game->mlx.win_ptr, 70, 28, WHI,
		ft_itoa(game->coins));
}

void	reset_texture(t_game *game)
{
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win_ptr, game->bg.ptr,
		game->pos_x * 35, game->pos_y * 35);
	if (game->map[game->pos_y][game->pos_x] == 'E')
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win_ptr,
			game->exit.ptr, game->pos_x * 35, game->pos_y * 35);
	if (game->map[game->pos_y][game->pos_x] == 'C')
		game->map[game->pos_y][game->pos_x] = '0';
}

void	win(t_game *game)
{
	int	logo_x;
	int	logo_y;
	int	color;

	game->moves++;
	write(1, "Moves : ", 8);
	ft_putnbr_fd(game->moves, 1);
	write(1, "\n", 1);
	color = rgb_to_int(255, 255, 255);
	logo_x = game->mlx.w / 2 - 41;
	logo_y = game->mlx.h / 2 - 50;
	game->end = 1;
	draw_bg(game);
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win_ptr,
		game->success.ptr, logo_x, logo_y);
	mlx_string_put(game->mlx.ptr, game->mlx.win_ptr, logo_x + 12,
		logo_y + 92, color, "Moves");
	mlx_string_put(game->mlx.ptr, game->mlx.win_ptr, logo_x + 52,
		logo_y + 92, color, ft_itoa(game->moves));
	mlx_string_put(game->mlx.ptr, game->mlx.win_ptr, logo_x + 12,
		logo_y + 102, color, "Coins");
	mlx_string_put(game->mlx.ptr, game->mlx.win_ptr, logo_x + 52,
		logo_y + 102, color, ft_itoa(game->coins));
}

int	deal_key(int key, t_game *game)
{
	if (key == 53)
		exit_game(game, NULL);
	if (game->end)
		return (0);
	if (key == 13)
		move_up(game);
	if (key == 1)
		move_down(game);
	if (key == 0)
		move_left(game);
	if (key == 2)
		move_right(game);
	return (0);
}
